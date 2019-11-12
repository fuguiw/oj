package main

import "fmt"

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func findDuplicates(nums []int) []int {
	for _, n := range nums {
		i := abs(n) - 1
		nums[i] = -nums[i]
	}

	var result []int
	for _, n := range nums {
		i := abs(n) - 1
		if nums[i] > 0 {
			result = append(result, i+1)
			nums[i] = -nums[i]
		}
	}

	return result
}
