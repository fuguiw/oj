package main

import "sort"

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func minDays(bloomDay []int, m int, k int) int {
	maxBloom := 0
	for _, bloom := range bloomDay {
		maxBloom = max(maxBloom, bloom)
	}
	left, right := 0, maxBloom

	isValid := func(limit int) bool {
		count := 0
		for i := 0; i < len(bloomDay); i++ {
			if bloomDay[i] <= limit {
				j := i
				for ; j < i+k && j < len(bloomDay); j++ {
					if bloomDay[j] > limit {
						break
					}
				}
				if j == i+k {
					count++
					j--
				}
				i = j
			}
		}
		return count >= m
	}

	for left < right {
		mid := (left + right) / 2
		if isValid(mid) {
			right = mid
		} else {
			left = mid + 1
		}
	}

	if isValid(left) {
		return left
	}
	return -1
}
