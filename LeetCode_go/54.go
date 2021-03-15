package main

func spiralOrder(matrix [][]int) []int {
	n, m := len(matrix), len(matrix[0])

	var ans []int
	printCycle := func(idx int) {
		i, j := idx, idx
		for ; j < m-idx; j++ {
			ans = append(ans, matrix[i][j])
		}
		for i, j = idx+1, m-idx-1; i < n-idx; i++ {
			ans = append(ans, matrix[i][j])
		}
		for i, j = n-idx-1, m-idx-2; idx != n-idx-1 && j >= idx; j-- {
			ans = append(ans, matrix[i][j])
		}
		for i, j = n-idx-2, idx; idx != m-idx-1 && i > idx; i-- {
			ans = append(ans, matrix[i][j])
		}
	}

	for i := 0; i <= (n-1)/2 && i <= (m-1)/2; i++ {
		printCycle(i)
	}

	return ans
}
