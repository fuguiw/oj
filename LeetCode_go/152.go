package main

import "math"

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	return x + y - max(x, y)
}

func maxProduct(nums []int) int {
	pos := 1
	neg := 1
	result := math.MinInt32

	for _, n := range nums {
		pos, neg = max(n, max(pos*n, neg*n)), min(n, min(pos*n, neg*n))
		result = max(result, pos)
	}
	return result
}
