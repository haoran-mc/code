/***
*  创建日期：2022/05/01 Sun 20:43:56
*  题目来源：<++>
*  算    法：<++>
*  描    述：<++>
**/

package main

import "fmt"

const maxn = 1000

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func submaxmin(num []int, l, r int) (maxi, mini, submaxi, submini int) {
	if r-l <= 1 { // 说明到达边界
		maxi = max(num[l], num[r])
		mini = min(num[l], num[r])
		submaxi = min(num[l], num[r])
		submini = max(num[l], num[r])
	} else { // 分治寻找
		mid := (l + r) >> 1

		// l            mid            r
		// |-------------+-------------|
		l_maxi, l_mini, l_submaxi, l_submini := submaxmin(num, l, mid)
		r_maxi, r_mini, r_submaxi, r_submini := submaxmin(num, mid+1, r)

		maxi = max(l_maxi, r_maxi)
		mini = min(l_mini, r_mini)
		submaxi = max(min(l_maxi, r_maxi), max(l_submaxi, r_submaxi))
		submini = min(max(l_mini, r_mini), min(l_submini, r_submini))
	}
	return
}

func main() {
    num := []int{9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
    n := len(num)
	// var n int
	// var num []int = make([]int, maxn)
	// fmt.Scanf("%d", &n)
	// for i := 0; i < n; i++ {
		// fmt.Scanf("%d", &num[i])
	// }
	maxi, mini, submaxi, submini := submaxmin(num, 0, n-1)
	fmt.Println(maxi, mini, submaxi, submini)
}
