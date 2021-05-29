package main

import "sort"

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func minPairSum(nums []int) int {
	sort.Ints(nums)
	ans := 0
	for i, j := 0, len(nums)-1; i < j; i, j = i+1, j-1 {
		ans = max(ans, nums[i]+nums[j])
	}
	return ans
}
