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

func maximumProduct(nums []int) int {
	var max1, max2, min1, min2 int = -1e9, -1e9, 1e9, 1e9

	ans := math.MinInt32
	for i, num := range nums {
		if i > 1 {
			ans = max(ans, max(num*max2, num*min2))
		}
		if i > 0 {
			max2 = max(max2, max(num*max1, num*min1))
			min2 = min(min2, min(num*max1, num*min1))
		}
		max1 = max(max1, num)
		min1 = min(min1, num)
	}

	return ans
}
