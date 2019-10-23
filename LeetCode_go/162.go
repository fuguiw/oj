package main

import "math"

func findPeakElement(nums []int) int {
	start, end := 0, len(nums)-1

	for start < end {
		mid := (start + end) / 2
		left, right := math.MinInt32, math.MinInt32
		if mid > 0 {
			left = nums[mid-1]
		}
		if mid < len(nums)-1 {
			right = nums[mid+1]
		}
		if nums[mid] > left && nums[mid] > right {
			return mid
		}
		if nums[mid] > left {
			start = mid + 1
		} else {
			end = mid - 1
		}
	}

	return nums[start]
}
