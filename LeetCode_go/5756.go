package main

import "math/bits"

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func minimumXORSum(nums1 []int, nums2 []int) int {
	n := len(nums1)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, 1<<n)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}
	dp[0][0] = 0

	for i := range nums1 {
		for j := 1; j < 1<<n; j++ {
			if bits.OnesCount(uint(j)) != i+1 {
				continue
			}
			for k := 0; k < n; k++ {
				if j&(1<<k) != 0 {
					if dp[i][j-(1<<k)] != -1 {
						if dp[i+1][j] == -1 {
							dp[i+1][j] = nums1[i] ^ nums2[k] + dp[i][j-(1<<k)]
						} else {
							dp[i+1][j] = min(dp[i+1][j], nums1[i]^nums2[k]+dp[i][j-(1<<k)])
						}
					}
				}
			}
		}
	}

	return dp[n][1<<n-1]
}
