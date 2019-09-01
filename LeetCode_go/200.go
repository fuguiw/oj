package main

func findIsland(grid [][]byte, i, j int) {
	if i < 0 || j < 0 || i >= len(grid) || j >= len(grid[i]) || grid[i][j] != '1' {
		return
	}

	grid[i][j] = '0'
	findIsland(grid, i-1, j)
	findIsland(grid, i+1, j)
	findIsland(grid, i, j-1)
	findIsland(grid, i, j+1)
}

func numIslands(grid [][]byte) int {
	result := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if grid[i][j] == '1' {
				result++
				findIsland(grid, i, j)
			}
		}
	}
	return result
}
