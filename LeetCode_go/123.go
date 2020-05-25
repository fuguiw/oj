package main

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxProfit(prices []int) int {
	n := len(prices)
	if n == 0 {
		return 0
	}
	p1 := make([]int, n+1)
	p2 := make([]int, n+1)

	m := prices[0]
	for i := 1; i < n; i++ {
		p1[i] = max(p1[i-1], prices[i]-m)
		m = min(m, prices[i])
	}
	m = prices[n-1]
	for i := n - 1; i >= 0; i-- {
		p2[i] = max(p2[i+1], m-prices[i])
		m = max(m, prices[i])
	}

	ans := 0
	for i := 0; i < n; i++ {
		ans = max(ans, p1[i]+p2[i+1])
	}

	return ans
}
