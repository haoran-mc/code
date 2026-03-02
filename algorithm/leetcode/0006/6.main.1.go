/*
 * author: haoran
 * email: haoran.mc@outlook.com
 * datetime: 02/04/2023 April 16:49:19 CST
 * question:
 * algorithm:
 * description:
 */

package main

import "fmt"

func main() {
	str := convert("PAYPALISHIRING", 3)
	fmt.Println(str)
}

const maxn int = 1e3 + 5

var arr [maxn][maxn]byte

func convert(s string, numRows int) string {
	if numRows == 1 || numRows >= len(s) {
		return s
	}
	var str string
	// 一共 numRows 行
	for i := 1; i <= numRows; i++ {
		for k := 0; ; k++ {
			if check(s, i, k, numRows) { // 第 k 次循环是否超过字符串的长度
				break
			}
			str += get(s, i, k, numRows) // 第 i 行，第 k 次循环的子串
		}
	}
	return str
}

func check(s string, i, k, numRows int) bool {
	if (2*k)*(numRows-1)+i-1 >= len(s) {
		return true
	}
	return false
}

func get(s string, i, k, numRows int) string {
	var cycle int = numRows - 1
	var str string = ""

	// 第一行和最后一行只加一次
	str += string(s[(2*k)*cycle+i-1])
	if i != 1 && i != numRows && (2*k)*cycle+(2*numRows-i)-1 < len(s) {
		str += string(s[(2*k)*cycle+(2*numRows-i)-1])
	}
	return str
}

/*
1         B
2       A C
3     9   D
4   8     E   I
5 7       F H
6         G

0         A
1       9 B
2     8   C
3   7     D   H
4 6       E G
5         F
*/

/*
------------------------->
\*(1, 1)
\
\
\
\
\
\
\_(1, n)          _(n, n)
V
*/
