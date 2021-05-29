package main

import "sort"

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func getBiggestThree(grid [][]int) []int {
	n, m := len(grid), len(grid[0])
	k := min(n, m)

	getSum := func(i, j, l int) int {
		if i+2*l >= n || j-l < 0 || j+l >= m {
			return -1
		}
		if l == 0 {
			return grid[i][j]
		}
		sum := 0
		sum += grid[i][j]
		sum += grid[i+2*l][j]
		sum += grid[i+l][j-l]
		sum += grid[i+l][j+l]
		for x := 1; x < l; x++ {
			sum += grid[i+x][j-x] + grid[i+x][j+x] + grid[i+2*l-x][j-x] + grid[i+2*l-x][j+x]
		}
		return sum
	}

	var ans []int
	exist := make(map[int]bool)
	for l := 0; l <= k/2; l++ {
		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				sum := getSum(i, j, l)
				if sum == -1 || exist[sum] {
					continue
				}
				exist[sum] = true
				ans = append(ans, sum)
			}
		}
	}
	sort.Sort(sort.Reverse(sort.IntSlice(ans)))
	return ans[0:min(len(ans), 3)]
}
