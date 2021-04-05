package main

import "math"

func magicTower(nums []int) int {
	tot := 1
	for _, num := range nums {
		tot += num
	}
	if tot <= 0 {
		return -1
	}

	n := len(nums)
	b := make([][]int, n+1)
	s := make([][]int, n+1)
	for i := range b {
		b[i] = make([]int, 2)
		s[i] = make([]int, 2)
	}
	b[0][0], b[0][1] = 1, 1

	for i, num := range nums {
		if num >= 0 {

		}
		if num >= max(b[i][0], b[i][1]) {
			b[i+1][0] = math.MaxInt32
			s[i+1][0] = math.MaxInt32
		} else {

		}
	}
}
