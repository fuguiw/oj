package main

func maxProfit(prices []int) int {
	m := make([]int, len(prices)+1)

	for i := len(prices) - 1; i >= 0; i-- {
		m[i] = prices[i]
		if prices[i] < m[i+1] {
			m[i] = m[i+1]
		}
	}

	result := 0
	for i := range prices {
		if result < m[i+1]-prices[i] {
			result = m[i+1] - prices[i]
		}
	}
	return result
}
