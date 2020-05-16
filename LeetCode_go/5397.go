package main

import "strconv"

func simplifiedFractions(n int) []string {
	var ans []string
	for i := 2; i <= n; i++ {
		for j := 1; j < i; j++ {
			k := 2
			for ; k <= j; k++ {
				if i%k == 0 && j%k == 0 {
					break
				}
			}
			if k > j {
				ans = append(ans, strconv.Itoa(j)+"/"+strconv.Itoa(i))
			}
		}
	}
	return ans
}
