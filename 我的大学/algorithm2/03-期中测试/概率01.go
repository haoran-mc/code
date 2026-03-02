package main

import (
    "fmt"
    "sort"
)

type Data struct {
    x int
    p float64
}

type DataSlice []Data

func (p DataSlice) Len() int {
    return len(p)
}

func (p DataSlice) Swap(i, j int) {
    p[i], p[j] = p[j], p[i]
}

func (p DataSlice) Less(i, j int) bool {
    return p[i].x < p[j].x
}

func Sum(l, r int, s []Data) float64 {
    res := 0.0
    for i := l; i <= r; i++ {
        res += s[i].p
    }
    return res
}

func findMidProbability(s []Data, p float64, l, r int) int {
    if l == r {
        return l
    }

    m := (l + r) >> 1
    sum := Sum(l, m, s)   // [l, m] 区间 s.p 的和
    if sum > p {
        return findMidProbability(s, p, l, m)
    } else {
        return findMidProbability(s, p-sum, m+1, r)
    }
}

func main() {
    var n int
    var s = []Data{}
    fmt.Scanf("%d", &n)

    for i := 0; i < n; i++ {
        var j Data
        fmt.Scanf("%d", &j.x)
        s = append(s, j)
    }

    for i := 0; i < n; i++ {
        fmt.Scanf("%f", &s[i].p)
    }

    sort.Sort(DataSlice(s))

    m := findMidProbability(s, 0.5, 0, n - 1)
    fmt.Println(s[m].x, s[m].p)
}
