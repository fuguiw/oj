package main

import "fmt"

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func longestLine(M [][]int) int {
	d := make([][][]int, len(M))
	for i := 0; i < len(d); i++ {
		d[i] = make([][]int, len(M[i]))
		for j := 0; j < len(d[i]); j++ {
			d[i][j] = make([]int, 4)
		}
	}

	ans := 0
	for i := 0; i < len(M); i++ {
		for j := 0; j < len(M[i]); j++ {
			if M[i][j] == 1 {
				d[i][j][0] = 1
				if j > 0 {
					d[i][j][0] += d[i][j-1][0]
				}
				ans = max(ans, d[i][j][0])
				d[i][j][1] = 1
				if i > 0 {
					d[i][j][1] += d[i-1][j][1]
				}
				ans = max(ans, d[i][j][1])
				d[i][j][2] = 1
				if i > 0 && j > 0 {
					d[i][j][2] += d[i-1][j-1][2]
				}
				ans = max(ans, d[i][j][2])
				d[i][j][3] = 1
				if i > 0 && j < len(M[i])-1 {
					d[i][j][3] += d[i-1][j+1][3]
				}
				ans = max(ans, d[i][j][3])
			}
		}
	}

	return ans
}
