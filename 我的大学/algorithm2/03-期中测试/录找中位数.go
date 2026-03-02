package main

import "fmt"

var cnt int = 10

func findmid(a, b []int, la, ra, lb, rb int) (mid float64) {
    ma := (la + ra) >> 1
    mb := (lb + rb) >> 1
	if a[ma] == b[mb] {
		mid = (float64)(a[ma])
	} else if la == ra && lb == rb {
		mid = ((float64)(a[ma]) + (float64)(b[mb])) / 2
	} else if a[ma] < b[mb] {
        if (ra - la + 1) % 2 == 0 {
            la = ma + 1
            rb = mb
        } else {
            la = ma
            rb = mb
        }
		mid = findmid(a, b, la, ra, lb, rb)
	} else if a[ma] > b[mb] {
        if (ra - la + 1) % 2 == 0 {
            ra = ma
            lb = mb + 1
        } else {
            ra = ma
            lb = mb
        }
		mid = findmid(a, b, la, ra, lb, rb)
	}
	return
}

func main() {
	a := []int{1, 3, 5, 7, 9}
	b := []int{2, 4, 6, 8, 10}
	mid := findmid(a, b, 0, 4, 0, 4)
	fmt.Println(mid)
}
