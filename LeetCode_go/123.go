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
	find := func(prices []int) int {
		if len(prices) == 0 {
			return 0
		}
		ans, m := 0, prices[0]
		for _, price := range prices {
			ans = max(ans, price-m)
			m = min(m, price)
		}
		return ans
	}

	ans := 0
	for i := 1; i < len(prices); i++ {
		ans = max(ans, find(prices[0:i])+find(prices[i:]))
	}

	return ans
}
