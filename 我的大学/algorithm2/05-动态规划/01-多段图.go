package main

import "fmt"

const (
    maxn = 100;    // 最多 100 个点
    maxv = 1000;   // 最多 1000 个边
)

var cost [maxv]int;
var g    [maxv][maxv]int;

func main() {
    var n, m int
    fmt.Scanf("%d %d", &n, &m)
    for i := 0; i < m; i++ {
        var vert1, vert2, edge int
        fmt.Scanf("%d %d %d", &vert1, &vert2, &edge);
        g[vert1][vert2] = edge;
    }
    for i := 1; i < n; i++ {
        cost[i] = 0x3f3f3f3f
    }
    cost[0] = 0;   // 源点到源点的距离为 0

    for i := 1; i < n; i++ {
        for j := 0; j < i; j++ {
            if g[j][i] != 0 {   // 节点 j 能到达节点 i
                s := cost[j] + g[j][i]   // 以节点 j 为枢纽需要的开销
                if s < cost[i] {   // 说明以节点 j 为枢纽花费更少
                    cost[i] = s;
                }
            }
        }
    }
    fmt.Println(cost[n-1])
}
