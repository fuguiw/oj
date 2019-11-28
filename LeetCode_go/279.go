package main

import "math"

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func numSquares(n int) int {
	d := make([]int, n+1)
	for i := 1; i <= n; i++ {
		d[i] = math.MaxInt32
		for j := 1; j*j <= i; j++ {
			d[i] = min(d[i], d[i-j*j]+1)
		}
	}

	return d[n]
}
