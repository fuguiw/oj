package main

func totalHammingDistance(nums []int) int {
	counts := make([]int, 31)

	for _, num := range nums {
		for i := 30; i >= 0; i-- {
			if num&(1<<i) != 0 {
				counts[i]++
			}
		}
	}

	ans := 0
	n := len(nums)
	for _, num := range nums {
		for i := 30; i >= 0; i-- {
			if num&(1<<i) == 0 {
				ans += counts[i]
			} else {
				ans += n - counts[i]
			}
		}
	}
	return ans / 2
}
