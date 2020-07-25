package main

func countOdds(low int, high int) int {
	ans := 0
	if low%2 == 0 {
		low--
		ans--
	}
	if high%2 == 0 {
		high++
		ans--
	}
	ans += (high - low) / 2
	if high%2 == 1 {
		ans++
	}
	return ans
}
