package main

func search(nums []int, target int) int {
	if len(nums) == 0 {
		return 0
	}
	left, right := 0, len(nums)-1
	for left < right {
		mid := (left + right) / 2
		if nums[mid] >= target {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	lower := left
	if nums[lower] == target {
		lower--
	}

	left, right = 0, len(nums)-1
	for left < right {
		mid := (left + right) / 2
		if nums[mid] > target {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	upper := left
	if nums[upper] == target {
		upper++
	}

	if upper == lower {
		return 0
	}

	return upper - lower - 1
}
