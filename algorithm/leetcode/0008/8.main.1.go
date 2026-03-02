/*
 * author: haoran
 * email: haoran.mc@outlook.com
 * datetime: 04/04/2023 April 18:53:05 CST
 * question: leetcode.cn 0008
 * algorithm:
 * description:
 */

package main

import (
	"fmt"
	"strings"
)

func main() {
	num := myAtoi("    -42")
	fmt.Println(num)
}

// 0 48
// 1 49
// 2 50...

var maxi int

func init() {
	var u uint32 = 0
	u--
	u--
	u /= 2
	u++
	maxi = int(u)
}

func myAtoi(s string) int {
	str := strings.Trim(s, " ")

	if len(str) == 0 {
		return 0
	}

	var negative bool
	if string(str[0]) == "-" {
		negative = true
	} else {
		negative = false
	}

	if string(str[0]) == "-" || string(str[0]) == "+" {
		str = str[1:]
	}

	var n int
	for i := 0; i < len(str); i++ {
		num := int(str[i] - '0')
		if num < 0 || num > 9 {
			break
		}
		n = 10*n + num
		if n > maxi {
			break
		}
	}

	if negative {
		if n > maxi {
			n = -maxi
		} else {
			n = -n
		}
	} else {
		if n > maxi-1 {
			n = maxi - 1
		}
	}

	return n
}
