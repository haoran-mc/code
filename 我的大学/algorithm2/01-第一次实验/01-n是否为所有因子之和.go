package main

import "fmt"

var facs []int

func findfac(sta, n int) {
    for i := sta; i < n; i ++ {
        if n % i == 0 {
            facs = append(facs, i)
            findfac(i + 1, n)
            break
        }
    }
}

func main() {
    var n int
    fmt.Scanln(&n)

    findfac(1, n)
    for _, v := range facs {
        n -= v
    }

    if n == 0 {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}
