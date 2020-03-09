package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxValue(grid [][]int) int {
	n, m := len(grid), len(grid[0])
	val := make([][]int, n)
	for i := 0; i < n; i++ {
		val[i] = make([]int, m)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			val[i][j] = grid[i][j]
			if i > 0 {
				val[i][j] = max(val[i-1][j]+grid[i][j], val[i][j])
			}
			if j > 0 {
				val[i][j] = max(val[i][j-1]+grid[i][j], val[i][j])
			}
		}
	}
	return val[n-1][m-1]
}
