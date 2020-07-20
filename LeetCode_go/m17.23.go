package main

import "fmt"

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func findSquare(matrix [][]int) []int {
	n := len(matrix)
	if n == 0 {
		return []int{}
	}
	m := len(matrix[0])
	r := make([][]int, n+1)
	c := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		r[i] = make([]int, m+1)
		c[i] = make([]int, m+1)
	}
	b := false
	for i := n - 1; i >= 0; i-- {
		for j := m - 1; j >= 0; j-- {
			if matrix[i][j] == 1 {
				continue
			}
			b = true
			r[i][j] = r[i+1][j] + 1
			c[i][j] = c[i][j+1] + 1
		}
	}
	if b == false {
		return []int{}
	}
	fmt.Println(r)
	fmt.Println(c)

	ans := make([]int, 3)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			l := min(r[i][j], c[i][j])
			for ; l >= 1; l-- {
				if r[i][j+l-1] >= l && c[i+l-1][j] >= l && ans[2] < l {
					ans[0], ans[1], ans[2] = i, j, l
					break
				}
			}
		}
	}

	return ans
}
