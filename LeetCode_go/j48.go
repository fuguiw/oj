package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func lengthOfLongestSubstring(s string) int {
	m := make(map[byte]int)

	ans := 0
	for i, j := 0, 0; j < len(s); {
		if m[s[j]] == 0 {
			m[s[j]]++
			ans = max(ans, j-i+1)
			j++
			continue
		}

		for ; i < j; i++ {
			m[s[i]]--
			if s[i] == s[j] {
				i++
				break
			}
		}
	}

	return ans
}
