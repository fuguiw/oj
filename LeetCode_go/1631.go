package main

import (
	"sort"
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

type unionFind struct {
	fa []int
}

func newUnion(n int) *unionFind {
	uf := &unionFind{}
	uf.fa = make([]int, n+1)
	for i := range uf.fa {
		uf.fa[i] = i
	}
	return uf
}

func (uf *unionFind) find(x int) int {
	if uf.fa[x] != x {
		uf.fa[x] = uf.find(uf.fa[x])
	}
	return uf.fa[x]
}

func (uf *unionFind) merge(x, y int) {
	uf.fa[uf.find(y)] = uf.find(x)
}

type edge struct {
	x, y, diff int
}

func minimumEffortPath(heights [][]int) int {
	n, m := len(heights), len(heights[0])
	var edges []edge
	for i := range heights {
		for j := range heights[i] {
			id := i*m + j
			if i > 0 {
				edges = append(edges, edge{id - m, id, abs(heights[i][j] - heights[i-1][j])})
			}
			if j > 0 {
				edges = append(edges, edge{id - 1, id, abs(heights[i][j] - heights[i][j-1])})
			}
		}
	}

	sort.Slice(edges, func(i, j int) bool {
		return edges[i].diff < edges[j].diff
	})

	uf := newUnion(n * m)
	for i := range edges {
		uf.merge(edges[i].x, edges[i].y)
		if uf.find(0) == uf.find(n*m-1) {
			return edges[i].diff
		}
	}

	return 0
}
