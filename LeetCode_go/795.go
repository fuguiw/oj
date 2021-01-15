package main

func numSubarrayBoundedMax(A []int, L int, R int) int {
	count := func(bound int) int {
		ans, cur := 0, 0
		for _, x := range A {
			if x <= bound {
				cur++
			} else {
				cur = 0
			}
			ans += cur
		}
		return ans
	}

	return count(R) - count(L-1)
}
