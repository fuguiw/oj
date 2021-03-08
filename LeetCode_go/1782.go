package main

import "sort"

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func countPairs(n int, edges [][]int, queries []int) []int {
	deg := make([]int, n+1)
	m := make(map[int]int)
	for _, edge := range edges {
		deg[edge[0]]++
		deg[edge[1]]++
		sort.Ints(edge)
		m[edge[0]*(n+1)+edge[1]]++
	}

	s := make([]int, len(deg))
	copy(s, deg)
	sort.Ints(s[1:])

	ans := make([]int, len(queries))
	for i, query := range queries {
		right := n
		for left := 1; left <= n; left++ {
			for left < right-1 {
				if s[left]+s[right-1] <= query {
					break
				}
				right--
			}
			if s[left]+s[right] > query {
				ans[i] += n - max(right, left+1) + 1
			}
		}
		for key, value := range m {
			u, v := key/(n+1), key%(n+1)
			if deg[u]+deg[v] > query && deg[u]+deg[v]-value <= query {
				ans[i]--
			}
		}
	}

	return ans
}
