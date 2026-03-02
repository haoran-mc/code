/***
*  创建日期：2022/05/01 Sun 20:10:38
*  题目来源：<++>
*  算    法：<++>
*  描    述：<++>
**/

package main

import "fmt"

func quick_sort(num []int, l, r, k int) int {
	if l >= r {
		return num[l]
	}

	i, j := l, r
	x := num[(l+r)>>1]
	for i < j {
		for num[i] < x {
			i++
		}
		for num[j] > x {
			j--
		}
		if i < j {
			num[i], num[j] = num[j], num[i]
		}
	}

	if j-l+1 >= k {
		return quick_sort(num, l, j, k)
	} else {
		return quick_sort(num, j+1, r, k-(j-l+1))
	}
}

func main() {
    num := []int{9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
    n := len(num)
    k := 8
    // const maxn = 1000
    // var n, k int
    // var num []int = make([]int, maxn)
	// fmt.Scanf("%d", &n)
	// for i := 0; i < n; i++ {
		// fmt.Scanf("%d", &num[i])
	// }
	// fmt.Scanf("%d", &k)

	fmt.Println(quick_sort(num, 0, n-1, k))
}
