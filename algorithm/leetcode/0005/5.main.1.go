/*
 * author: haoran
 * email: haoran.mc@outlook.com
 * datetime: 02/04/2023 April 15:00:35 CST
 * question: leetcode.cn 0139
 * algorithm: 字符串哈希 + 二分
 * description:
 */

package main

import "fmt"

func main() {
	str := longestPalindrome("sss")
	fmt.Println(str)
}

const base uint = 131
const maxn int = 2e3 + 5

var p [maxn]uint
var h1, h2 [maxn]uint

// 最长回文子串
func longestPalindrome(s string) string {
	// 1. 扩展为奇字符串
	str := expand(s)
	n := len(str)

	// 2. 计算前缀哈希，后缀哈希
	// 需要base = 131
	// 前缀数组 h1
	// 后缀数组 h2
	p[0] = 1 // p^0 = 1
	for i := 1; i < n; i++ {
		j := n - i
		h1[i] = h1[i-1]*base + uint(str[i])
		h2[i] = h2[i-1]*base + uint(str[j])
		p[i] = p[i-1] * base
	}

	// 3. 枚举中点，二分半径
	var res int = 0 // 扩展串的最长回文串的半径
	var pos int = 0 // 扩展串的最长回文串的开始位置
	for i := 1; i < n; i++ {
		l := 0
		r := min(i-1, n-1-i)
		for l < r {
			mid := (l + r + 1) / 2
			// 下取整 [l, mid] [mid+1, r]
			// 上取整 [l, mid-1] [mid, r]
			// oooooooo........
			if get(h1, i-mid, i) != get(h2, n-(i+mid), n-i) { // fail
				r = mid - 1
			} else { // success -> [mid, r]
				l = mid
			}
		}
		// 找到最大半径
		if l > res {
			res = l
			pos = (i - l) / 2
		}
	}
	return s[pos : pos+res]
}

func get(h [maxn]uint, l, r int) uint {
	return h[r] - h[l-1]*p[r-l+1]
}

func expand(str string) string {
	// 因为需要前缀哈希，所以下标从1开始
	expand_str := " #"
	for i := 0; i < len(str); i++ {
		expand_str += string(str[i])
		expand_str += "#"
	}
	// _#a#b#c#d#e#
	// 0123
	// _#a#c#b#c#   acbc
	return expand_str
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
