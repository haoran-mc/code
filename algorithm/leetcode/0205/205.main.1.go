/*
 * author: haoran
 * email: haoran.mc@outlook.com
 * datetime: 07/04/2023 April 18:05:24 CST
 * question:
 * algorithm:
 * description:
 */

package main

import "fmt"

func main() {
	if isIsomorphic("foo", "bar") {
		fmt.Println(1)
	} else {
		fmt.Println(0)
	}
}

func isIsomorphic(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	var mps map[byte]byte = make(map[byte]byte)
	var mpt map[byte]byte = make(map[byte]byte)

	for i := 0; i < len(s); i++ {
		bs := mps[s[i]]
		bt := mpt[t[i]]

		// 不能只有一方被映射
		if (bs == 0 && bt != 0) || (bt == 0 && bs != 0) {
			return false
		}

		if bs == 0 && bt == 0 { // 未被映射
			mps[s[i]] = t[i]
			mpt[t[i]] = s[i]
		} else if bs == t[i] && bt == s[i] { // 映射成功
			continue
		} else {
			return false
		}
	}
	return true
}
