package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func averageWaitingTime(customers [][]int) float64 {
	n := len(customers)
	t := make([]int, n)

	for i, c := range customers {
		if i == 0 {
			t[i] = c[0] + c[1]
		} else {
			t[i] = max(t[i-1], c[0]) + c[1]
		}
	}

	w := 0
	for i := range t {
		w += t[i] - customers[i][0]
	}

	return float64(w) / float64(n)
}
