package main

func addToArrayForm(A []int, K int) []int {
	n := len(A)
	A[n-1] += K
	p := 0
	var ans []int
	for i := len(A) - 1; i >= 0; i-- {
		w := A[i] + p
		ans = append([]int{w % 10}, ans...)
		p = w / 10
	}
	for p > 0 {
		ans = append([]int{p % 10}, ans...)
		p /= 10
	}

	return ans
}
