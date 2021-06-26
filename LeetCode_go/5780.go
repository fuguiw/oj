package main

func isCrease(nums []int) bool {
	for i := 1; i < len(nums); i++ {
		if nums[i] <= nums[i-1] {
			return false
		}
	}
	return true
}

func canBeIncreasing(nums []int) bool {
	for i := 1; i < len(nums); i++ {
		if nums[i] <= nums[i-1] {
			n1 := append([]int{}, nums[:i]...)
			n1 = append(n1, nums[i+1:]...)
			n2 := append([]int{}, nums[:i-1]...)
			n2 = append(n2, nums[i:]...)
			if !isCrease(append(n1)) && !isCrease(n2) {
				return false
			} else {
				return true
			}
		}
	}
	return true
}
