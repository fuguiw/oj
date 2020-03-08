package main

import (
	"sort"
	"strconv"
)

func minNumber(nums []int) string {
	sort.Slice(nums, func(i, j int) bool {
		a := strconv.Itoa(nums[i])
		b := strconv.Itoa(nums[j])
		return a+b < b+a
	})

	var ans string
	for _, num := range nums {
		ans += strconv.Itoa(num)
	}

	return ans
}
