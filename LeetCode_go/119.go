package main

func getRow(k int) []int {
	ans := make([]int, k+1)
	ans[0] = 1
	for i := 0; i <= k; i++ {
		for j := i; j > 0; j-- {
			ans[j] += ans[j-1]
		}
	}

	return ans
}
