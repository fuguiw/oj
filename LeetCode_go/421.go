package main

func findMaximumXOR(nums []int) int {
	ans := 0
	for high := 30; high >= 0; high-- {
		seen := map[int]bool{}
		for _, num := range nums {
			seen[num>>high] = true
		}

		next := ans<<1 + 1
		found := false
		for _, num := range nums {
			if seen[(num>>high)^next] {
				found = true
				break
			}
		}

		ans = next
		if !found {
			ans--
		}
	}

	return ans
}
