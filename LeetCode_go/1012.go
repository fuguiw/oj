package main

import "fmt"

func dfs(nums []int, dp [][][]int, m []int, pos int, pre int, limit bool) int {
	if pos == 0 {
		if pre == 0 {
			return 0
		}
		return 1
	}

	c := 0
	for i := 0; i <= 9; i++ {
		if m[i] != 0 {
			c++
		}
	}
	if !limit && dp[pos][c][pre] != 0 {
		return dp[pos][c][pre]
	}

	up := 9
	if limit {
		up = nums[pos]
	}

	ans := 0
	for i := 0; i <= up; i++ {
		if m[i] != 0 {
			continue
		}

		p := 1
		if pre == 0 && i == 0 {
			p = 0
		}

		if i != 0 || pre != 0 {
			m[i]++
		}
		ans += dfs(nums, dp, m, pos-1, p, limit && i == nums[pos])
		if i != 0 || pre != 0 {
			m[i]--
		}
	}

	dp[pos][c][pre] = ans
	fmt.Println(ans)
	return ans
}

func solve(n int) int {
	nums := make([]int, 11)
	len := 1
	for n != 0 {
		nums[len] = n % 10
		len++
		n /= 10
	}

	dp := make([][][]int, 11)
	for i := range dp {
		dp[i] = make([][]int, 11)
		for j := range dp[i] {
			dp[i][j] = make([]int, 2)
		}
	}
	m := make([]int, 11)

	return dfs(nums, dp, m, len-1, 0, true)
}

func numDupDigitsAtMostN(N int) int {
	return N - solve(N)
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	fmt.Println(numDupDigitsAtMostN(n))
}
