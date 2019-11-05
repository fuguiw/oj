package main

import "sort"

func treeDiameter(edges [][]int) int {
	g := make(map[int][]int)
	for _, e := range edges {
		g[e[0]] = append(g[e[0]], e[1])
		g[e[1]] = append(g[e[1]], e[0])
	}
	res := 0
	depth(-1, 0, g, &res)
	return res
}

func depth(p, u int, g map[int][]int, res *int) int {
	m := []int{0, 0}
	for _, v := range g[u] {
		if v == p {
			continue
		}
		d := depth(u, v, g, res)
		m = append(m, d)
		sort.Slice(m, func(i, j int) bool {
			return m[i] > m[j]
		})
		m = m[:2]
	}
	if m[0]+m[1]+1 > *res {
		*res = m[0] + m[1]
	}
	return m[0] + 1
}
