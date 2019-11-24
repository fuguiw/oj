package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func lengthOfLongestSubstring(s string) int {
	m := make(map[byte]int)
	res := 0
	for begin, end := -1, 0; end < len(s); end++ {
		for m[s[end]] > 0 {
			begin++
			m[s[begin]]--
		}
		m[s[end]]++
		res = max(res, end-begin)
	}

	return res
}
