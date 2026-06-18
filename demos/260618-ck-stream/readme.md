
```bash
CH_PASSWORD=xxx

CH_MODE=stream go run .
CH_MODE=batch go run .
```

`clickhouse-go/v2` 的 `conn.Query(...)` + `rows.Next()` 是一种流式消费方式。

对照的 `batch` 模式则是先把结果全部读到切片里，再开始处理。这样更方便做全量操作，但首条结果出来会更晚，而且更吃内存。

## 哪些场景不适合流式尽早返回

- 需要全局 `ORDER BY`
- 需要全局 `GROUP BY`
- 需要 `DISTINCT`
- 需要窗口函数
- 大范围 `JOIN`
- 需要先聚合、再排序、再取结果的报表类 SQL

这类 SQL 即便客户端用 `rows.Next()`，服务端也往往要先把大部分中间结果算出来，才能开始返回数据。也就是说，接口层面是流式的，执行层面不一定能“边查边出”。

## 代码里的两种模式

- `runStreamQuery`：`rows.Next()` 处理一行，更符合“边查边处理”的目标
- `runBatchQuery`：把所有行放到 `[]resultRow`，再统一处理，适合做对照实验
