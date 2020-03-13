package main

import "math"

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
func max(x, y int) int {
	return x + y - min(x, y)
}

func maxProfit(prices []int) int {
	m, ans := math.MaxInt32, 0

	for _, p := range prices {
		m = min(m, p)
		ans = max(ans, p-m)
	}

	return ans
}
