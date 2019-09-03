package main

func subarraySum(nums []int, k int) int {
	sums := make([]int, len(nums)+1)
	for i := 1; i <= len(nums); i++ {
		sums[i] = nums[i-1] + sums[i-1]
	}

	result := 0
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j <= len(nums); j++ {
			if sums[j]-sums[i] == k {
				result++
			}
		}
	}

	return result
}
