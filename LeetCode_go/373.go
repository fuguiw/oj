package main

import (
	"sort"
)

func kSmallestPairs(nums1 []int, nums2 []int, k int) [][]int {
	var pairs [][]int

	for _, num1 := range nums1 {
		for _, num2 := range nums2 {
			pairs = append(pairs, []int{num1, num2})
		}
	}

	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i][0]+pairs[i][1] < pairs[j][0]+pairs[j][1]
	})

	if k > len(nums1)*len(nums2) {
		k = len(nums1) * len(nums2)
	}

	return pairs[:k]
}
