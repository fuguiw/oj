package main

import (
	"math"
	"sort"
)

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func minDifference(nums []int) int {
	n := len(nums)
	if n <= 4 {
		return 0
	}

	sort.Ints(nums)
	ans := math.MaxInt32
	//fmt.Println(nums)

	for i := 0; i <= 3; i++ {
		j := n - 4 + i
		//fmt.Println(i, j)
		if j >= 0 && i <= j {
			ans = min(ans, nums[j]-nums[i])
		}
	}

	return ans
}
