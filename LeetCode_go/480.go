package main

import (
	"fmt"
	"sort"
)

func medianSlidingWindow(nums []int, k int) []float64 {
	var window []int
	var ans []float64
	for i, num := range nums {
		idx := sort.SearchInts(window, num)
		new := append([]int{}, window[idx:]...)
		window = append(append(window[:idx], num), new...)

		if len(window) > k {
			idx := sort.SearchInts(window, nums[i-k])
			window = append(window[:idx], window[idx+1:]...)
		}
		if len(window) == k {
			mid := float64(window[k/2]+window[(k-1)/2]) / 2
			ans = append(ans, mid)
		}
	}

	return ans
}
