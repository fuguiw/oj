package main

func leastBricks(wall [][]int) int {
	m := map[int]int{}
	for _, row := range wall {
		sum := 0
		for _, brick := range row {
			sum += brick
			m[sum]++
		}
		m[sum]--
	}

	ans := 0
	for _, v := range m {
		if v > ans {
			ans = v
		}
	}
	return len(wall) - ans
}
