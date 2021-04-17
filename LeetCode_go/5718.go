package main

func countPoints(points [][]int, queries [][]int) []int {
	ans := make([]int, len(queries))

	find := func(i int) int {
		query := queries[i]
		count := 0
		for _, point := range points {
			d1 := point[0] - query[0]
			d2 := point[1] - query[1]
			if d1*d1+d2*d2 <= query[2]*query[2] {
				count++
			}
		}
		return count
	}

	for i := range queries {
		ans[i] = find(i)
	}

	return ans
}
