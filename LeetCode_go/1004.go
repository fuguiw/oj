package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func longestOnes(A []int, K int) int {
	ans := 0
	k := K
	for begin, end := 0, 0; end < len(A); end++ {
		if A[end] == 0 {
			if k > 0 {
				k--
			} else {
				for ; begin <= end; begin++ {
					if A[begin] == 0 {
						begin++
						break
					}
				}
			}
		}
		ans = max(ans, end-begin)
		if A[end] == 1 || k >= 0 {
			ans = max(ans, end-begin+1)
		}
	}

	return ans
}
