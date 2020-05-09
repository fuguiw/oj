package main

func findWhetherExistsPath(n int, graph [][]int, start int, target int) bool {
	m := make(map[int][]int)

	for _, v := range graph {
		m[v[0]] = append(m[v[0]], v[1])
	}

	v := make([]bool, n)

	var dfs func(int) bool
	dfs = func(s int) bool {
		v[s] = true
		for _, node := range m[s] {
			if node == target {
				return true
			}
			if !v[node] && dfs(node) {
				return true
			}
		}
		return false
	}

	return dfs(start)
}
