package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func longestOnes(A []int, K int) (ans int) {
	var left, lsum, rsum int
	for right, a := range A {
		rsum += 1 - a
		for lsum < rsum-K {
			lsum += 1 - A[left]
			left++
		}
		ans = max(ans, right-left+1)
	}
	return ans
}
