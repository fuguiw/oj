package main

func findRedundantConnection(edges [][]int) []int {
	fa := make([]int, 1e3+1)
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

	ans := make([]int, 2)
	for _, edge := range edges {
		if find(edge[0]) == find(edge[1]) {
			ans[0], ans[1] = edge[0], edge[1]
		}
		merge(edge[0], edge[1])
	}

	return ans
}
