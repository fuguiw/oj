package main

import "math"

func maxSubArray(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	s, ans := math.MinInt32, math.MinInt32

	for _, num := range nums {
		if s > 0 {
			s += num
		} else {
			s = num
		}
		if s > ans {
			ans = s
		}
	}

	return ans
}
