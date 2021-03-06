package main

import (
	"fmt"
	"sort"
)

func isValid(nums []int, n int, idx int) bool {
	if n == 0 {
		return true
	}
	for ; idx < len(nums); idx++ {
		if nums[idx] > n {
			break
		}
		if isValid(nums, n-nums[idx], idx+1) == true {
			return true
		}
	}

	return false
}

func checkPowersOfThree(n int) bool {
	nums := []int{1}
	num := 1
	for i := 0; num*3 <= 1e7; i++ {
		num *= 3
		nums = append(nums, num)
	}

	for i := range nums {
		if isValid(nums, n, i) == true {
			return true
		}
	}

	return false
}
