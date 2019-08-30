package main

import "fmt"

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func longestConsecutive(nums []int) int {
	n := make(map[int]int)

	for _, num := range nums {
		n[num] = 1
	}

	result := 0
	for _, num := range nums {
		begin, end := num, num
		for ; n[begin] == 1; begin-- {
			n[begin] = 0
		}
		n[end] = 1
		for ; n[end] == 1; end++ {
			n[end] = 0
		}

		result = max(result, end-begin+1)
	}

	return result
}
