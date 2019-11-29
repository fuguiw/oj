package main

import (
	"sort"
)

func findUnsortedSubarray(nums []int) int {
	s := make([]int, len(nums))
	copy(s, nums)
	sort.Slice(s, func(x, y int) bool {
		return s[x] < s[y]
	})

	var i int
	for i = 0; i < len(nums); i++ {
		if nums[i] != s[i] {
			break
		}
	}

	for j := len(nums) - 1; j > i; j-- {
		if nums[j] != s[j] {
			return j - i + 1
		}
	}

	return 0
}
