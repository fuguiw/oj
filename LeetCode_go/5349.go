package main

import (
	"sort"
)

func maxNumberOfFamilies(n int, reservedSeats [][]int) int {
	sort.Slice(reservedSeats, func(i, j int) bool {
		return reservedSeats[i][0] < reservedSeats[j][0]
	})

	ans := 2 * n

	m := make(map[int]bool)
	for i, line := 0, -1; i <= len(reservedSeats); i++ {
		if i == len(reservedSeats) || reservedSeats[i][0] != line {
			var s1, s2, s3 bool
			if len(m) != 0 {
				if !m[2] && !m[3] && !m[4] && !m[5] {
					s1 = true
				}
				if !m[6] && !m[7] && !m[8] && !m[9] {
					s2 = true
				}
				if !m[4] && !m[5] && !m[6] && !m[7] {
					s3 = true
				}

				if s1 && s2 {
				} else if s3 {
					ans--
				} else if s1 || s2 {
					ans--
				} else {
					ans -= 2
				}
			}

			if i == len(reservedSeats) {
				break
			}
			line = reservedSeats[i][0]
			m = make(map[int]bool)
			m[reservedSeats[i][1]] = true
		} else {
			m[reservedSeats[i][1]] = true
		}
	}

	return ans
}
