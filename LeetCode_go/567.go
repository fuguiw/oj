package main

import "reflect"

func checkInclusion(s1 string, s2 string) bool {
	n1, n2 := len(s1), len(s2)
	m1 := make(map[byte]int)
	for i := range s1 {
		m1[s1[i]]++
	}
	m2 := make(map[byte]int)

	for s, e := 0, 0; e < n2; e++ {
		m2[s2[e]]++
		if e-s+1 > n1 {
			m2[s2[s]]--
			if m2[s2[s]] == 0 {
				delete(m2, s2[s])
			}
			s++
		}
		if e-s+1 == n1 && reflect.DeepEqual(m1, m2) {
			return true
		}
	}

	return false
}
