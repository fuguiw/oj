package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func networkDelayTime(times [][]int, N int, K int) int {
	m := make(map[int][][]int)
	for _, time := range times {
		a, b, t := time[0], time[1], time[2]
		m[a] = append(m[a], []int{b, t})
	}

	vis := make([]int, N+1)
	for i := range vis {
		vis[i] = -1
	}
	vis[K] = 0
	var dfs func(n int, l int)
	dfs = func(n int, l int) {
		for _, next := range m[n] {
			if vis[next[0]] == -1 {
				vis[next[0]] = l + next[1]
				dfs(next[0], vis[next[0]])
			} else {
				if vis[next[0]] > l+next[1] {
					vis[next[0]] = l + next[1]
					dfs(next[0], vis[next[0]])
				}
			}
		}
	}
	dfs(K, 0)

	ans := 0
	for i := 1; i <= N; i++ {
		if vis[i] == -1 {
			return -1
		}
		ans = max(ans, vis[i])
	}

	return ans
}
