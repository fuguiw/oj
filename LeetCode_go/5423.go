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

func minSumOfLengths(arr []int, target int) int {
	n := len(arr)
	sum := make([]int, n+1)
	for i := 0; i < n; i++ {
		sum[i+1] = sum[i] + arr[i]
	}

	a := make([]int, 3)
	b := make([]int, 3)
	a[2], b[2] = math.MaxInt32, math.MaxInt32
	for i, j := 0, 1; j <= n && i < n; {
		s := sum[j] - sum[i]
		if s > target {
			i++
		} else if s < target {
			j++
		} else {
			//fmt.Println(i, j, j-i, a[0], a[1], a[2], b[0], b[1], b[2])
			l := j - i
			if l < b[2] {
				if i < a[1] {
					if l < a[2] {
						a[0], a[1], a[2] = i, j, j-i
					}
				} else {
					b[0], b[1], b[2] = i, j, j-i
				}
			}

			if a[2] > b[2] {
				a, b = b, a
			}
			i++
			j++
		}
	}

	if b[2] == math.MaxInt32 {
		return -1
	}
	return a[2] + b[2]
}
