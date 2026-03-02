/*
 * author: haoran
 * email: haoran.mc@outlook.com
 * datetime: 22/03/2023 March 14:36:08 CST
 * algorithm:
 * description:
 */

package main

import (
	"container/list"
	"fmt"
)

func main() {
	length := lengthOfLongestSubstring(" ")
	fmt.Println(length)
}

func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	var maxlen int = 0
	q := list.New()
	mp := make(map[rune]int)

	for i, r := range s {
		// 1. 是否出现过
		// 2. 如果出现过
		//    2.1 更新长度
		//    2.2 不断出队
		//    2.3 进队
		// 3. 如果没出现过，进队
		if _, ok := mp[r]; ok {
			hh := q.Front().Value.(rune) // 队头
			pos := mp[hh]                // 队头位置
			maxlen = max(maxlen, i-pos)  // 更新长度
			// 出队
			for true {
				hh = q.Front().Value.(rune)
				q.Remove(q.Front()) // 一定会找到的，不需要判断队列长度
				delete(mp, hh)
				if hh == r {
					break
				}
			}
		}
		mp[r] = i // 记录窗口中存在的字符及位置
		q.PushBack(r)
	}
	// 最后剩余在队列中的字符串长度
	maxlen = max(maxlen, q.Len())
	return maxlen
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
