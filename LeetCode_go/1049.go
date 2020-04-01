package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func lastStoneWeightII(stones []int) int {
	sum := 0
	for _, stone := range stones {
		sum += stone
	}

	cap := sum / 2
	dp := make([]int, cap+1)

	for _, stone := range stones {
		for j := cap; j >= stone; j-- {
			dp[j] = max(dp[j], dp[j-stone]+stone)
		}
	}

	return sum - 2*dp[cap]
}
