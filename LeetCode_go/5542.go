package main

const mod int = 1000000007

func numWays(words []string, target string) int {
	n := len(words[0])

	counts := make([][]int, n)
	for i := range counts {
		counts[i] = make([]int, 26)
	}

	for _, word := range words {
		for i := range word {
			counts[i][word[i]-'a']++
		}
	}

	m := len(target)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, m)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}

	var find func(int, int) int
	find = func(i int, j int) int {
		if j == m {
			return 1
		}
		if n-i < m-j {
			return 0
		}
		if dp[i][j] != -1 {
			return dp[i][j]
		}

		ans := counts[i][target[j]-'a'] * find(i+1, j+1)
		ans += find(i+1, j)
		ans %= mod
		dp[i][j] = ans
		return ans
	}

	return find(0, 0)
}
