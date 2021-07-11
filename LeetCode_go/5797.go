package main

import "sort"

func maxProductDifference(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	a, b, c, d := nums[n-1], nums[n-2], nums[0], nums[1]
	return a*b - c*d
}
