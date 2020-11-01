package main

func countSubstrings(s string, t string) int {
	n, m := len(s), len(t)

	dp1 := make([][]int, n+1)
	dp2 := make([][]int, n+1)
	for i := range dp1 {
		dp1[i] = make([]int, m+1)
		dp2[i] = make([]int, m+1)
	}

	ans := 0
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if s[i-1] == t[j-1] {
				dp2[i][j] = dp2[i-1][j-1]
				dp1[i][j] = dp1[i-1][j-1] + 1
			} else {
				dp2[i][j] = dp1[i-1][j-1] + 1
			}
			ans += dp2[i][j]
		}
	}

	return ans
}
