package main

func regionsBySlashes(grid []string) int {
	n := len(grid)
	fa := make([]int, n*n*4)
	for i := range fa {
		fa[i] = i
	}

	var find func(int) int
	find = func(x int) int {
		if fa[x] != x {
			fa[x] = find(fa[x])
		}
		return fa[x]
	}

	merge := func(x, y int) {
		fa[find(y)] = find(x)
	}

	getBlockIdx := func(i, j int) int {
		return (i*n + j) * 4
	}

	for i := range grid {
		for j := range grid[i] {
			idx := getBlockIdx(i, j)
			if grid[i][j] == ' ' {
				merge(idx, idx+1)
				merge(idx, idx+2)
				merge(idx, idx+3)
			} else if grid[i][j] == '/' {
				merge(idx, idx+1)
				merge(idx+2, idx+3)
			} else if grid[i][j] == '\\' {
				merge(idx, idx+3)
				merge(idx+1, idx+2)
			}
			if i > 0 {
				merge(getBlockIdx(i-1, j)+3, idx+1)
			}
			if j > 0 {
				merge(getBlockIdx(i, j-1)+2, idx)
			}
		}
	}

	ans := 0
	for i := range fa {
		if find(i) == i {
			ans++
		}
	}

	return ans
}
