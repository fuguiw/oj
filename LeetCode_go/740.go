package main

import (
	"sort"
)

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func deleteAndEarn(nums []int) int {
	count := map[int]int{}
	for _, num := range nums {
		count[num]++
	}

	sort.Ints(nums)
	dp := make([]int, 2)

	for i, j := 0, 0; j < len(nums); i++ {
		p := dp[1]
		if j > 0 && nums[j]-1 != nums[j-1] {
			p = max(p, dp[0])
		}
		dp[0], dp[1] = p+nums[j]*count[nums[j]], max(dp[0], dp[1])
		j += count[nums[j]]
	}

	return max(dp[0], dp[1])
}
