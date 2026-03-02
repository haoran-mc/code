/*
 * author: haoran
 * email: haoran.mc@outlook.com
 * datetime: 07/04/2023 April 17:58:27 CST
 * question:
 * algorithm:
 * description:
 */

package main

func main() {
}

// len(s), len(t) <= 5e4
func isAnagram(s string, t string) bool {
	var mps map[byte]int = make(map[byte]int)
	var mpt map[byte]int = make(map[byte]int)

	for i := 0; i < len(s); i++ {
		mps[s[i]]++
	}

	for i := 0; i < len(t); i++ {
		mpt[t[i]]++
	}

	var flag bool = true
	for k, v := range mps {
		if mpt[k] != v {
			flag = false
			break
		}
	}

	for k, v := range mpt {
		if mps[k] != v {
			flag = false
			break
		}
	}
	return flag
}
