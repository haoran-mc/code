/*
 * author: haoran
 * email: haoran.mc@outlook.com
 * datetime: 07/04/2023 April 18:24:02 CST
 * question:
 * algorithm:
 * description:
 */

package main

func main() {
}

func countSubstrings(s string) int {
	var cnt int = 0
	for i := 0; i < len(s); i++ {
		for j := 0; j <= i; j++ {
			if palindrome(s, i, j) {
				cnt++
			}
		}
	}
	return cnt
}

func palindrome(s string, i, j int) bool {
	for j < i {
		if s[j] != s[i] {
			return false
		}
		i--
		j++
	}
	return true
}
