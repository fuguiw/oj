package main

func minPatches(nums []int, n int) int {
	m := 1
	ans := 0
	for _, num := range nums {
		for num > m && m < n {
			m *= 2
			ans++
		}
		m += num
		if m >= n {
			break
		}
	}
	for m <= n/2 {
		ans++
		m *= 2
	}
	if m < n {
		ans++
	}

	return ans
}
