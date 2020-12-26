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

func minMoves(nums []int, k int) int {
	var pos []int
	for i, num := range nums {
		if num == 1 {
			pos = append(pos, i)
		}
	}

	ans := math.MaxInt32
	n := len(pos)
	pre := make([]int, n+1)
	for i := range pos {
		pre[i+1] = pre[i] + pos[i]
	}

	for i := 0; i+k <= n; i++ {
		x := pos[i+k/2] - k/2
		y := pos[i+k/2]
		l := k / 2
		r := k - l
		step := x*l + l*(l-1)/2 - (pre[i+k/2] - pre[i])
		step += (pre[i+k] - pre[i+k/2]) - (y*r + r*(r-1)/2)
		ans = min(ans, step)
	}

	return ans
}
