package main

func find(n int, p []int, m []int) bool {
	if m[n] == 1 {
		return true
	}
	if m[n] == -1 {
		return false
	}

	m[n] = -1
	for i := 0; p[i] <= n; i++ {
		if find(n-p[i], p, m) == false {
			m[n] = 1
			break
		}
	}

	return find(n, p, m)
}

func winnerSquareGame(n int) bool {
	var p []int
	m := make([]int, 100001)
	m[1] = 1
	m[0], m[2] = -1, -1
	for i := 1; i*i <= 100000; i++ {
		p = append(p, i*i)
	}

	return find(n, p, m)
}
