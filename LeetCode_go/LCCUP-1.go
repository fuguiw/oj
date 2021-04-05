package main

import "sort"

const mod = 1e9 + 7

func purchasePlans(nums []int, target int) int {
	sort.Ints(nums)
	ans := 0

	for i, num := range nums {
		if num >= target {
			break
		}
		j := sort.SearchInts(nums[i+1:], target-num+1)
		ans = (ans + j) % mod
	}

	return ans
}
