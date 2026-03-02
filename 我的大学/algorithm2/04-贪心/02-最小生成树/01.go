package main

import (
    "fmt"
)

const (
    maxn = 500 + 5
    INF = 0x3f3f3f3f
)

var n, m int
var g = [maxn][maxn]int{}
var dist = [maxn]int{}
var used = [maxn]bool{}

func Min(a, b int) int {
    if a < b {
        return a
    } else {
        return b
    }
}

/**
 * 这里res存储的是最小生成树上所有边权之和
 * 如果确定有最小生成树，可以返回空void
 * 然后把所有的res删除，dist[]中是这棵树的所有边权
 */
func prim() int {
    for i := 1; i <= n; i++ {
        dist[i] = INF
        used[i] = false
    }
    source := 1   // 设置源点，不然下面的判断语句要额外判断是否是源点
    dist[source] = 0
    res := 0
    for i := 0; i < n; i++ {   // 这个循环只是为了将n个点都加入集合中，下标无所谓
        vert := -1  // 用vert找到集合外最近的点
        for j := 1; j <= n; j++ {   // 根据题目要求设置下标开始的位置
            if !used[j] && (vert == -1 || dist[j] < dist[vert]) {
                vert = j
            }
        }
        used[vert] = true   // 找到后标记true
        if dist[vert] == INF {   // 如果不能形成最小生成树，一般不会，除非这个点不连通
            return INF
        }
        // 用新加入集合中的点vert更新未进入集合的点到集合的距离
        for j := 1; j <= n; j++ {
            if !used[j] {
                dist[j] = Min(dist[j], g[vert][j])
            }
        }
        res += dist[vert]
    }
    return res
}

func main() {
    fmt.Scanf("%d %d", &n, &m)
    for i := 1; i <= n; i++ {
        for j := 1; j <= n; j++ {
            g[i][j] = INF
        }
    }
    for m != 0 {
        m --
        var a, b, c int
        fmt.Scanf("%d %d %d", &a, &b, &c)
        c = Min(g[a][b], c)   // 解决重环
        g[a][b] = c
        g[b][a] = c
    }
    res := prim()
    if res >= INF {
        fmt.Printf("no spanning tree\n");
    } else {
        fmt.Printf("%d\n", res);
    }
}
