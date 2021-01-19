package main

import "sort"

type pair struct {
	a, b int
	dis  int
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func minCostConnectPoints(points [][]int) int {
	var pairs []pair
	for i := range points {
		for j := i + 1; j < len(points); j++ {
			a, b := points[i], points[j]
			pairs = append(pairs, pair{i, j, abs(a[0]-b[0]) + abs(a[1]-b[1])})
		}
	}

	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i].dis < pairs[j].dis
	})

	fa := make([]int, len(points))
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

	ans, cnt := 0, 0
	for _, pair := range pairs {
		if find(pair.a) == find(pair.b) {
			continue
		}
		merge(pair.a, pair.b)
		cnt++
		ans += pair.dis
		if cnt == len(points)-1 {
			break
		}
	}
	return ans
}
