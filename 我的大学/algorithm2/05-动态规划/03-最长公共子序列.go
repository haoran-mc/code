package main

import "fmt"

const maxn = 1000   // 规定字符串最长不超过 1000
var dp [maxn][maxn]int

func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

func main() {
    var a, b string
    fmt.Scanf("%s", &a)
    fmt.Scanf("%s", &b)

    a = " " + a
    b = " " + b

    n, m := len(a), len(b)

    for i := 1; i < n; i++ {
        for j := 1; j < m; j++ {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])
            if a[i] == b[j] {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1)
            }
        }
    }

    fmt.Println(dp[n-1][m-1])
}
