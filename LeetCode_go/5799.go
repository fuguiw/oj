package main

func wonderfulSubstrings(word string) int64 {
	dp := make([]int, 1<<11)
	dp[0] = 1
	var ans int64
	state := 0
	for i := range word {
		c := int(word[i] - 'a')
		state ^= 1 << c
		ans += int64(dp[state])
		for j := 0; j < 10; j++ {
			ans += int64(dp[state^1<<j])
		}
		dp[state] += 1
	}

	return ans
}
