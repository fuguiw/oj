package main

func getSumAbsoluteDifferences(nums []int) []int {
	n := len(nums)
	sum := make([]int, n)
	s := 0
	for i, num := range nums {
		s += num
		sum[i] = s
	}

	ans := make([]int, n)
	for i, num := range nums {
		if i > 0 {
			ans[i] += (i+1)*num - sum[i]
		}
		if i < n-1 {
			ans[i] += sum[n-1] - sum[i] - (n-1-i)*num
		}
	}

	return ans
}
