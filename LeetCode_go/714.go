package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxProfit(prices []int, fee int) int {
	if prices == nil || len(prices) == 0 {
		return 0
	}

	var buy, sell int
	buy = -prices[0]
	for i := 1; i < len(prices); i++ {
		buy, sell = max(buy, sell-prices[i]), max(sell, buy+prices[i]-fee)
	}

	return sell
}
