package main

func sum(i, j int) int {
	s := 0
	for ; i > 0; i /= 10 {
		s += i % 10
	}
	for ; j > 0; j /= 10 {
		s += j % 10
	}
	return s
}

func dfs(v [][]int, m, n int, x, y int, k int, ans *int) {
	f := [][]int{
		{0, 1},
		{1, 0},
		{-1, 0},
		{0, -1},
	}

	for c := 0; c < 4; c++ {
		i, j := x+f[c][0], y+f[c][1]
		if i < 0 || i >= m || j < 0 || j >= n || v[i][j] == 1 {
			continue
		}
		if sum(i, j) <= k {
			v[i][j] = 1
			*ans++
			dfs(v, m, n, i, j, k, ans)
		}
	}
}

func movingCount(m int, n int, k int) int {
	v := make([][]int, m)
	for i := 0; i < m; i++ {
		v[i] = make([]int, n)
	}
	v[0][0] = 1
	ans := 1
	dfs(v, m, n, 0, 0, k, &ans)
	return ans
}
