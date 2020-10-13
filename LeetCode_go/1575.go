package main

const mod int = 1000000007

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func countRoutes(locations []int, start int, finish int, fuel int) int {
	n := len(locations)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, fuel+1)
	}

	ans := 0
	dp[start][0] = 1
	for f := 0; f <= fuel; f++ {
		for i := range locations {
			for j := range locations {
				next := f + abs(locations[i]-locations[j])
				//fmt.Println(i, j, f, pre)
				if i == j || next > fuel {
					continue
				}
				dp[j][next] = (dp[j][next] + dp[i][f]) % mod
			}
		}
	}

	for f := 0; f <= fuel; f++ {
		ans = (ans + dp[finish][f]) % mod
	}

	return ans
}
