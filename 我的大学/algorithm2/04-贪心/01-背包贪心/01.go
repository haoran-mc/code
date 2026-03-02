package main

import (
    "fmt"
    "sort"
)

const maxn = 100

type Goods struct {
    id int64
    w float64   // 重量 weight
    v float64   // 价值 value
    p float64   // 单价 unit price
    r float64   // 使用率 ratio
}

type GoodSlice []Goods

func (g GoodSlice) Len() int {
    return len(g)
}

func (g GoodSlice) Swap(i, j int) {
    g[i], g[j] = g[j], g[i]
}

func (g GoodSlice) Less(i, j int) bool {
    return g[i].p > g[j].p
}

func main() {
    var n int     // n 商品数量
    var m float64   // m 背包容量
    goods := []Goods{}
    rate  := [maxn]float64{}
    fmt.Scanf("%d %f", &n, &m)

    for i := 0; i < n; i++ {
        var g Goods
        fmt.Scanf("%d %f %f", &g.id, &g.v, &g.w)
        g.p = g.v / g.w   // 计算性价比
        g.r = 1.0         // 初始化使用率
        goods = append(goods, g)
    }

    sort.Sort(GoodSlice(goods))

    idx := 0
    for ; idx < n; idx++ {
        if goods[idx].w <= m {
            goods[idx].r = 1
            m -= goods[idx].w
            rate[goods[idx].id] = goods[idx].r
        } else {
            break
        }
    }

    if idx < n {
        goods[idx].r = m / goods[idx].w
        m = 0
        rate[goods[idx].id] = goods[idx].r
    }
    for i := 1; i <= n; i++ {
        fmt.Printf("%.2f ", rate[i])
    }
}
