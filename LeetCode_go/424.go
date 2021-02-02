package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func characterReplacement(s string, k int) int {
	num := make(map[byte]int)
	maxn := 0
	var left, right int
	for left, right = 0, 0; right < len(s); right++ {
		num[s[right]]++
		maxn = max(maxn, num[s[right]])
		if right-left+1-maxn > k {
			num[s[left]]--
			left++
		}
	}
	return right - left
}
