package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func find(arr []int, dp [][]int, m [][]int, begin, end int) {
	if begin == end {
		m[begin][end] = arr[begin]
	}
	if m[begin][end] != 0 {
		return
	}

	for i := begin; i < end; i++ {
		find(arr, dp, m, begin, i)
		find(arr, dp, m, i+1, end)
		d := m[begin][i]*m[i+1][end] + dp[begin][i] + dp[i+1][end]
		if dp[begin][end] == 0 || d < dp[begin][end] {
			dp[begin][end] = d
			m[begin][end] = max(m[begin][i], m[i+1][end])
		}
	}
}

func mctFromLeafValues(arr []int) int {
	dp := make([][]int, len(arr))
	m := make([][]int, len(arr))
	for i := 0; i < len(arr); i++ {
		dp[i] = make([]int, len(arr))
		m[i] = make([]int, len(arr))
	}

	find(arr, dp, m, 0, len(arr)-1)

	return dp[0][len(arr)-1]
}
