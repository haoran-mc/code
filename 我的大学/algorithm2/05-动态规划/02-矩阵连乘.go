package main

import "fmt"

const maxn = 10;
var p [maxn]int
var dp [maxn][maxn]int

func min(a, b int) int {
    if a < b {
        return a
    } else {
        return b
    }
}

func main() {
    var n int
    fmt.Scanf("%d", &n)

    for i := 1; i <= n+1; i++ {
        fmt.Scanf("%d", &p[i])
    }

    for r := 2; r <= n; r++ {
        for l := r; l >= 1; l-- {
            if l == r {
                dp[l][r] = 0
            } else {
                dp[l][r] = 0x3f3f3f3f
            }
            for k := l; k < r; k++ {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + p[l] * p[k+1] * p[r+1])
            }
        }
    }

    fmt.Println(dp[1][n])
}
