package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func findTheLongestSubstring(s string) int {
	pos := make([]int, 1<<5)
	for i := range pos {
		pos[i] = -1
	}
	status, ans := 0, 0
	pos[0] = 0
	for i := 0; i < len(s); i++ {
		switch s[i] {
		case 'a':
			status ^= 1 << 0
		case 'e':
			status ^= 1 << 1
		case 'i':
			status ^= 1 << 2
		case 'o':
			status ^= 1 << 3
		case 'u':
			status ^= 1 << 4
		}
		if pos[status] >= 0 {
			ans = max(ans, i-pos[status]+1)
		} else {
			pos[status] = i + 1
		}
	}
	return ans
}
