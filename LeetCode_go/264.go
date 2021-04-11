package main

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func nthUglyNumber(n int) int {
	nums := make([]int, n)
	nums[0] = 1
	i2, i3, i5 := 0, 0, 0
	for i := 1; i < n; i++ {
		n2 := nums[i2] * 2
		n3 := nums[i3] * 3
		n5 := nums[i5] * 5
		next := min(n2, min(n3, n5))
		if next == n2 {
			i2++
		}
		if next == n3 {
			i3++
		}
		if next == n5 {
			i5++
		}
		nums[i] = next
	}

	return nums[n-1]
}
