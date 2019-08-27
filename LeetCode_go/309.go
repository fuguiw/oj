package main

func maxProfit(prices []int) int {
	profits := make([]int, len(prices))

	result := 0
	for i := 1; i < len(prices); i++ {
		profits[i] = profits[i-1]
		for j := i - 1; j >= 0; j-- {
			tmp := prices[i] - prices[j]
			if j > 1 {
				tmp += profits[j-2]
			}
			if tmp > profits[i] {
				profits[i] = tmp
			}
			if profits[i] > result {
				result = profits[i]
			}
		}
	}

	return result
}
