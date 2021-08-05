package main

func eventualSafeNodes(graph [][]int) []int {
	n := len(graph)
	nodes := make([]int, n)

	var dfs func(int, int)
	dfs = func(node int, begin int) {
		if nodes[node] == -1 || nodes[node] == -2 {
			return
		}
		if nodes[node] == begin {
			nodes[node] = -1
		} else {
			nodes[node] = begin
		}

		for _, next := range graph[node] {
			dfs(next, begin)
			if nodes[next] == -1 {
				nodes[node] = -1
			}
		}
		if nodes[node] != -1 {
			nodes[node] = -2
		}
	}
	for i := range graph {
		dfs(i, i+1)
	}
	var ans []int
	for i := range nodes {
		if nodes[i] != -1 {
			ans = append(ans, i)
		}
	}
	return ans
}
