package main

func findMin(nums []int) int {
	left, right := 0, len(nums)-1
	if nums[left] <= nums[right] {
		return nums[left]
	}

	for left < right {
		mid := (left + right) >> 1
		if nums[mid] >= nums[0] {
			left = mid + 1
		} else {
			right = mid
		}
	}

	return nums[left]
}
