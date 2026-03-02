
func lengthOfLongestSubstring(s string) (ans int) {
	mp := [128]int{} // 哈希表
	left := 0
	for right, c := range s {
		mp[c]++
		for mp[c] > 1 {
			mp[s[left]]--
			left++
		}
		ans = max(ans, right-left+1)
	}
	return
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
