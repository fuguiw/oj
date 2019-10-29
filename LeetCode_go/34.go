package main

func searchRange(nums []int, target int) []int {
	begin, end := -1, -1

	left, right := 0, len(nums)-1
	for left <= right {
		mid := (left + right) / 2
		if nums[mid] >= target {
			right = mid - 1
			if nums[mid] == target {
				begin = mid
			}
		} else {
			left = mid + 1
		}
	}

	left, right = 0, len(nums)-1
	for left <= right {
		mid := (left + right) / 2
		if nums[mid] > target {
			right = mid - 1
		} else {
			left = mid + 1
			if nums[mid] == target {
				end = mid
			}
		}
	}

	return []int{begin, end}
}
