/*
 * author: haoran
 * email: haoran.mc@outlook.com
 * datetime: 02/04/2023 April 15:01:34 CST
 * question: leetcode.cn 0139
 * algorithm: manacher
 * description:
 */

package main

import "fmt"

func main() {
	str := longestPalindrome("madam")
	fmt.Println(str)
}

// right most str
type rightmoststr struct {
	mid int
	r   int
}

const maxn int = 2e3 + 5

var radius [maxn]int

// manacher
func longestPalindrome(s string) string {
	str := expand(s)
	n := len(str)

	rmstr := rightmoststr{}

	// 1. 维护一个最右回文子串
	for i := 1; i < n-1; i++ {
		// 2.1 i > rmstr.r
		// 2.2 i < rmstr.r  jl > rmstr.l
		// 2.3 i < rmstr.r  jl = rmstr.l
		// 2.4 i < rmstr.r  jl < rmstr.l
		if i > rmstr.r {
			radius[i] = 0
		} else {
			j := 2*rmstr.mid - i
			radius[i] = min(radius[j], rmstr.r-i)
		}
		// 暴力拓展
		// 因为 $，不需要关心边界
		for str[i+radius[i]+1] == str[i-radius[i]-1] {
			radius[i]++
		}
		if i+radius[i] > rmstr.r {
			rmstr = rightmoststr{
				mid: i,
				r:   i + radius[i],
			}
		}
	}

	// ^#a#b#c#d#c#$
	// 0123456789
	var res int = 0
	var pos int = 0
	for i := 1; i < n-1; i++ { // 不要考虑最后一个 $
		if radius[i] > res {
			res = radius[i]
			pos = (i - radius[i]) / 2
		}
	}
	fmt.Println(pos, res)
	return s[pos : pos+res]
}

func expand(str string) string {
	expand_str := "^#"
	for i := 0; i < len(str); i++ {
		expand_str += string(str[i])
		expand_str += "#"
	}
	expand_str += "$"
	return expand_str
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
