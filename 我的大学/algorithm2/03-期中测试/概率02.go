package main

import "fmt"

type Data struct {
    x int
    p float64
}

func Sum(l, r int, s []Data) float64 {
    sum := 0.0
    for i := l; i <= r; i++ {
        sum += s[i].p
    }
    return sum
}

// 获取在切片 s [l, r] 区间中排序后左侧数权重和小于 pl 且右侧数权重和小于 pr 的数
func findMidProbability(s []Data, pl, pr float64, l, r int) int {
    m := (l + r) >> 1      // 中位数
    x := s[m].x            // 哨兵
    i, j := l, r           // 不修改当前子区间

    for i < j {
        for s[i].x < x {
            i++
        }
        for s[j].x > x {
            j--
        }
        if i < j {
            s[i], s[j] = s[j], s[i]
        }
    }

    // 这个时候 i == j，且 s[i].x == x
    suml := Sum(l, i-1, s)
    sumr := Sum(i+1, r, s)

    if suml < pl && sumr < pr {
        return i
    } else if suml > pl {
        return findMidProbability(s, pl, pr-sumr-s[i].p, l, i-1)
    } else {
        return findMidProbability(s, pl-suml-s[i].p, pr, i+1, r)
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

    i := findMidProbability(s, 0.5, 0.5, 0, n - 1)
    fmt.Println(s[i].x, s[i].p)
}
