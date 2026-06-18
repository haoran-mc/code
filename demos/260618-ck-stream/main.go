package main

import (
	"context"
	"fmt"
	"log"
	"os"
	"strings"
	"time"

	clickhouse "github.com/ClickHouse/clickhouse-go/v2"
	"github.com/ClickHouse/clickhouse-go/v2/lib/driver"
)

func main() {
	conn, err := openClickHouse()
	if err != nil {
		log.Fatalf("open clickhouse failed: %v", err)
	}

	ctx, cancel := context.WithTimeout(context.Background(), 2*time.Minute)
	defer cancel()

	query := `
SELECT
    number,
    now()
FROM system.numbers
LIMIT 1000000000000
`

	mode := strings.ToLower(getenv("CH_MODE", "stream"))
	switch mode {
	case "stream":
		err = runStreamQuery(ctx, conn, query)
	case "batch":
		err = runBatchQuery(ctx, conn, query)
	default:
		log.Fatalf("unsupported CH_MODE=%q, expected stream or batch", mode)
	}

	if err != nil {
		log.Fatal(err)
	}
}

func runStreamQuery(ctx context.Context, conn driver.Conn, query string) error {
	rows, err := conn.Query(ctx, query)
	if err != nil {
		return fmt.Errorf("stream query failed: %w", err)
	}
	defer rows.Close()

	startedAt := time.Now()
	var (
		count      int
		number     uint64
		serverTime time.Time
	)

	for rows.Next() {
		if err := rows.Scan(&number, &serverTime); err != nil {
			return fmt.Errorf("stream scan failed: %w", err)
		}

		count++
		if count <= 5 || count%10000 == 0 {
			fmt.Printf("row=%d number=%d server_time=%s elapsed=%s\n",
				count,
				number,
				serverTime.Format(time.RFC3339Nano),
				time.Since(startedAt).Truncate(time.Millisecond),
			)
		}
	}

	if err := rows.Err(); err != nil {
		return fmt.Errorf("stream read failed: %w", err)
	}

	fmt.Printf("stream done, rows=%d total_elapsed=%s\n", count, time.Since(startedAt).Truncate(time.Millisecond))
	return nil
}

func runBatchQuery(ctx context.Context, conn driver.Conn, query string) error {
	rows, err := conn.Query(ctx, query)
	if err != nil {
		return fmt.Errorf("batch query failed: %w", err)
	}
	defer rows.Close()

	type resultRow struct {
		Number     uint64
		ServerTime time.Time
	}

	startedAt := time.Now()
	var allRows []resultRow

	for rows.Next() {
		var item resultRow
		if err := rows.Scan(&item.Number, &item.ServerTime); err != nil {
			return fmt.Errorf("batch scan failed: %w", err)
		}
		allRows = append(allRows, item)
	}

	if err := rows.Err(); err != nil {
		return fmt.Errorf("batch read failed: %w", err)
	}

	bufferedAt := time.Since(startedAt).Truncate(time.Millisecond)
	fmt.Printf("batch buffered all rows=%d buffered_elapsed=%s\n", len(allRows), bufferedAt)

	for idx, item := range allRows {
		row := idx + 1
		if row <= 5 || row%10000 == 0 {
			fmt.Printf("row=%d number=%d server_time=%s elapsed=%s\n",
				row,
				item.Number,
				item.ServerTime.Format(time.RFC3339Nano),
				time.Since(startedAt).Truncate(time.Millisecond),
			)
		}
	}

	fmt.Printf("batch done, rows=%d total_elapsed=%s\n", len(allRows), time.Since(startedAt).Truncate(time.Millisecond))
	return nil
}

func openClickHouse() (driver.Conn, error) {
	host := getenv("CH_HOST", "127.0.0.1")
	port := getenvInt("CH_PORT", 9000)
	database := getenv("CH_DATABASE", "default")
	username := getenv("CH_USER", "default")
	password := os.Getenv("CH_PASSWORD")

	return clickhouse.Open(&clickhouse.Options{
		Addr: []string{fmt.Sprintf("%s:%d", host, port)},
		Auth: clickhouse.Auth{
			Database: database,
			Username: username,
			Password: password,
		},
		DialTimeout: 5 * time.Second,
		Settings: clickhouse.Settings{
			"max_block_size": 1000,
		},
		Compression: &clickhouse.Compression{
			Method: clickhouse.CompressionLZ4,
		},
		Debug: false,
	})
}

func getenv(key, fallback string) string {
	if value := os.Getenv(key); value != "" {
		return value
	}
	return fallback
}

func getenvInt(key string, fallback int) int {
	value := os.Getenv(key)
	if value == "" {
		return fallback
	}

	var result int
	if _, err := fmt.Sscanf(value, "%d", &result); err != nil {
		log.Fatalf("invalid integer env %s=%q: %v", key, value, err)
	}
	return result
}