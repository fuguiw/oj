package main

import (
	"sort"
)

func longestDiverseString(a int, b int, c int) string {
	v := make([][]int, 3)
	v[0] = append(v[0], []int{0, a}...)
	v[1] = append(v[1], []int{1, b}...)
	v[2] = append(v[2], []int{2, c}...)

	var ans string
	for len(ans) < a+b+c {
		sort.Slice(v, func(i, j int) bool {
			return v[i][1] > v[j][1]
		})

		if len(ans) > 0 && ans[len(ans)-1] == byte(v[0][0]+'a') {
			if v[1][1] > 0 {
				ans += string(v[1][0] + 'a')
				v[1][1]--
			} else {
				return ans
			}
		} else {
			for i := 0; i < 2; i++ {
				if v[0][1] > 0 {
					ans += string(v[0][0] + 'a')
					v[0][1]--
				}
			}
		}
	}

	return ans
}
