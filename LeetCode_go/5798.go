package main

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func rotateGrid(grid [][]int, k int) [][]int {
	n, m := len(grid), len(grid[0])

	var rotate func(int)
	rotate = func(level int) {
		r, c := n-2*level, m-2*level
		count := r*2 + c*2 - 4
		for tk := k % count; tk > 0; tk-- {
			i, j := level, level
			pre := grid[i][j]
			for ; i < n-level; i++ {
				grid[i][j], pre = pre, grid[i][j]
			}
			for i, j = i-1, j+1; j < m-level; j++ {
				grid[i][j], pre = pre, grid[i][j]
			}
			for i, j = i-1, j-1; i >= level; i-- {
				grid[i][j], pre = pre, grid[i][j]
			}
			for i, j = i+1, j-1; j >= level; j-- {
				grid[i][j], pre = pre, grid[i][j]
			}
		}
	}

	level := min(n, m)
	for i := 0; i < level/2; i++ {
		rotate(i)
	}

	return grid
}
