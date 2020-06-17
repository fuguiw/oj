package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxScoreSightseeingPair(A []int) int {
	ans, mx := 0, A[0]+0
	for j := 1; j < len(A); j++ {
		ans = max(ans, mx+A[j]-j)
		mx = max(mx, A[j]+j)
	}
	return ans
}
