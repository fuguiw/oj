package main

func firstMissingPositive(nums []int) int {
	for i := 0; i < len(nums); {
		n := nums[i]
		if n > 0 && n <= len(nums) {
			if n-1 > i && nums[n-1] != n {
				nums[i], nums[n-1] = nums[n-1], n
				continue
			}
			nums[n-1] = n
		}
		i++
	}

	for i := 0; i < len(nums); i++ {
		if nums[i] != i+1 {
			return i + 1
		}
	}

	return len(nums) + 1
}
