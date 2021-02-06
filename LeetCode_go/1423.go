package main

import "math"

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func maxScore(cardPoints []int, k int) int {
	n := len(cardPoints)
	k = n - k
	tP, sP, ans := 0, 0, math.MaxInt32
	for i, point := range cardPoints {
		tP += point
		sP += point
		if i >= k {
			sP -= cardPoints[i-k]
		}
		if i >= k-1 {
			ans = min(ans, sP)
		}
	}

	return tP - ans
}
