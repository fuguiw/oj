package main

func finalPrices(prices []int) []int {
	n := len(prices)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if prices[j] <= prices[i] {
				prices[i] -= prices[j]
				break
			}
		}
	}

	return prices
}
