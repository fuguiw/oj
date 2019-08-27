package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxProfit(prices []int) int {
	if prices == nil || len(prices) == 0 {
		return 0
	}
	buy := -prices[0]
	sell := 0
	cooldown := 0

	for i := 1; i < len(prices); i++ {
		buy, sell, cooldown = max(buy, cooldown-prices[i]), max(buy+prices[i], sell), sell
	}

	return max(sell, cooldown)
}
