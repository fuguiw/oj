package main

func findCircleNum(isConnected [][]int) int {
	n := len(isConnected)
	fa := make([]int, n)
	for i := range fa {
		fa[i] = i
	}

	var find func(int) int
	find = func(i int) int {
		if fa[i] != i {
			fa[i] = find(fa[i])
		}
		return fa[i]
	}
	union := func(i, j int) {
		fa[find(i)] = find(fa[j])
	}

	for i := range isConnected {
		for j := range isConnected[i] {
			if isConnected[i][j] == 1 {
				union(i, j)
			}
		}
	}

	ans := 0
	for i := range fa {
		if i == fa[i] {
			ans++
		}
	}
	return ans
}
