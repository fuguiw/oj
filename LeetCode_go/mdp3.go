package main

func climbStairs(n int) int {
	p, pp, ans := 1, 0, 0

	for i := 1; i <= n; i++ {
		ans = p + pp
		pp, p = p, ans
	}

	return ans
}
