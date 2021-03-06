package main

import "sort"

func countPairs(n int, edges [][]int, queries []int) []int {
	adj := make([][]int, n+1)
	m := make(map[int]int)
	for _, edge := range edges {
		adj[edge[0]] = append(adj[edge[0]], edge[1])
		adj[edge[1]] = append(adj[edge[1]], edge[0])
		sort.Ints(edge)
		m[edge[0]*1e5+edge[1]]++
	}

	var cs []int
	for i := 1; i < n; i++ {
		for j := i + 1; j <= n; j++ {
			cs = append(cs, len(adj[i])+len(adj[j])-m[i*1e5+j])
		}
	}

	ans := make([]int, len(queries))
	for i, query := range queries {
		for _, c := range cs {
			if c > query {
				ans[i]++
			}
		}
	}

	return ans
}
