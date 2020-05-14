package main

import (
	"math"
)

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func minFallingPathSum(A [][]int) int {
	ans := math.MaxInt32
	d := make([]int, len(A[0])+2)
	pre := make([]int, len(A[0])+2)
	d[0], d[len(A[0])+1] = math.MaxInt32, math.MaxInt32
	for i := range A {
		for j := range A[i] {
			if i == 0 {
				d[j+1] = A[i][j]
			} else {
				d[j+1] = min(pre[j], min(pre[j+1], pre[j+2])) + A[i][j]
			}
			if i == len(A)-1 {
				ans = min(ans, d[j+1])
			}
		}
		copy(pre, d)
	}
	return ans
}
