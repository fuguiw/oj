package main

import "strings"

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func longestSubstring(s string, k int) (ans int) {
	cnt := make([]int, 26)
	for i := range s {
		cnt[s[i]-'a']++
	}

	split := -1
	for i, c := range cnt {
		if 0 < c && c < k {
			split = i
			break
		}
	}

	if split == -1 {
		return len(s)
	}

	for _, subStr := range strings.Split(s, string('a'+byte(split))) {
		ans = max(ans, longestSubstring(subStr, k))
	}

	return ans
}
