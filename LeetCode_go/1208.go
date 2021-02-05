package main

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func equalSubstring(s string, t string, maxCost int) int {
	ans := 0
	begin := -1
	for i := range s {
		maxCost -= abs(int(s[i]) - int(t[i]))
		for maxCost < 0 {
			begin++
			maxCost += abs(int(s[begin]) - int(t[begin]))
		}
		ans = max(ans, i-begin)
	}

	return ans
}
