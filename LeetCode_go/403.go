package main

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func canCross(stones []int) bool {
	//dp[i][j]   dp[i][k] && abs(stones[j] - stones[k] - (stones[k] - stones[i])) <= 1
	n := len(stones)
	dp := make([][]bool, n)
	for i := range dp {
		dp[i] = make([]bool, n)
	}
	dp[0][0] = true
	ans := false
	for i := range stones {
		for j := i; j < n; j++ {
			if !dp[i][j] {
				continue
			}
			for k := j + 1; k < n; k++ {
				s := (stones[k] - stones[j]) - (stones[j] - stones[i])
				dp[j][k] = dp[j][k] || (abs(s) <= 1)
				if k == n-1 {
					ans = ans || dp[j][k]
				}
			}
		}
	}
	return ans
}
