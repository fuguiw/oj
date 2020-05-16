package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxPower(s string) int {
	cnt, ans := 0, 0
	c := s[0]
	for i := range s {
		if s[i] == c {
			cnt++
		} else {
			cnt = 1
			c = s[i]
		}
		ans = max(ans, cnt)
	}
	return ans
}
