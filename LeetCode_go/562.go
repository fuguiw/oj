package main

import "fmt"

func longestLine(M [][]int) int {
	ans := 0

	var dfs func(m [][]int, move [][]int, i, j int, l *int)
	dfs = func(m [][]int, move [][]int, i, j int, l *int) {
		for k := 0; k < 2; k++ {
			ti := i + move[k][0]
			tj := j + move[k][1]
			if ti >= 0 && ti < len(m) && tj >= 0 && tj < len(m[ti]) && m[ti][tj] == 1 {
				m[ti][tj] = 0
				*l++
				if *l > ans {
					ans = *l
				}
				dfs(m, move, ti, tj, l)
			}
		}
	}

	f := func(m [][]int, move [][]int) {
		for i := 0; i < len(m); i++ {
			for j := 0; j < len(m[i]); j++ {
				if m[i][j] == 1 {
					m[i][j] = 0
					l := 1
					if l > ans {
						ans = l
					}
					dfs(m, move, i, j, &l)
				}
			}
		}
	}

	m := make([][]int, len(M))
	for i := 0; i < len(M); i++ {
		m[i] = make([]int, len(M[i]))
	}

	init := func(m [][]int, M [][]int) {
		for i := 0; i < len(M); i++ {
			copy(m[i], M[i])
		}
	}
	init(m, M)
	f(m, [][]int{{0, -1}, {0, 1}})
	init(m, M)
	f(m, [][]int{{-1, 0}, {1, 0}})
	init(m, M)
	f(m, [][]int{{-1, -1}, {1, 1}})
	init(m, M)
	f(m, [][]int{{-1, 1}, {1, -1}})

	return ans
}
