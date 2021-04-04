package main

func numRabbits(answers []int) int {
	m := make(map[int]int)
	for _, answer := range answers {
		m[answer]++
	}
	ans := 0
	for k, v := range m {
		ans += ((v+1)/(k+1) + 1) * (k + 1)
	}
	return ans
}
