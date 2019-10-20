package main

import (
	"fmt"
	"sort"
	"strconv"
)

func largestNumber(nums []int) string {
	sort.Slice(nums, func(i, j int) bool {
		stri := strconv.Itoa(nums[i])
		strj := strconv.Itoa(nums[j])

		return stri+strj > strj+stri
	})

	var result string
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] == 0 && len(result) == 0 {
			continue
		}
		result += strconv.Itoa(nums[i])
	}
	result += strconv.Itoa(nums[len(nums)-1])

	return result
}
