package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func longestArithSeqLength(A []int) int {
	n := len(A)
	ans := 0
	m := make([]map[int]int, n)
	for i := range A {
		m[i] = make(map[int]int)
		for j := i - 1; j >= 0; j-- {
			d := A[i] - A[j]
			if _, ok := m[j][d]; ok {
				m[i][d] = max(m[i][d], m[j][d]+1)
			} else if _, ok := m[i][d]; !ok {
				m[i][d] = 2
			}

			ans = max(ans, m[i][d])
		}
	}
	return ans
}
