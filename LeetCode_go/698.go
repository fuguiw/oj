package main

import (
	"fmt"
	"sort"
)

func find(nums []int, sum int, d []int, idx int) bool {
	fmt.Println(d)
	if idx == len(nums)-1 {
		for i := 0; i < len(d); i++ {
			if d[i]+nums[idx] == sum {
				return true
			}
		}
		return false
	}

	for i := 0; i < len(d); i++ {
		if d[i]+nums[idx] <= sum {
			d[i] += nums[idx]
			if find(nums, sum, d, idx+1) == true {
				return true
			}
			d[i] -= nums[idx]
		}
	}

	return false
}

func canPartitionKSubsets(nums []int, k int) bool {
	sum := 0
	for _, n := range nums {
		sum += n
	}

	if sum%k != 0 {
		return false
	}
	sum /= k

	sort.Slice(nums, func(i, j int) bool {
		return nums[i] > nums[j]
	})

	d := make([]int, k)
	return find(nums, sum, d, 0)
}
