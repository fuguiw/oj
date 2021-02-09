package main

import "fmt"

func subarraysWithKDistinct(A []int, K int) int {
	m := make(map[int]int)
	ans := 0
	for i, j := 0, 0; j < len(A); j++ {
		m[A[j]]++
		if len(m) < K {
			continue
		}

		for len(m) > K {
			m[A[i]]--
			if m[A[i]] == 0 {
				delete(m, A[i])
			}
			i++
		}

		tm := make(map[int]int)
		for ti := i; ti <= j; ti++ {
			fmt.Println(ti, j)
			ans++
			tm[A[ti]]++
			if m[A[ti]] == tm[A[ti]] {
				break
			}
		}

	}
	return ans
}
