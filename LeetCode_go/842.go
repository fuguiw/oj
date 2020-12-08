package main

import (
	"math"
	"strconv"
)

func splitIntoFibonacci(S string) []int {
	n := len(S)
	for i := 0; i <= n/3; i++ {
		f1, err := strconv.Atoi(S[0 : i+1])
		if err != nil || f1 > math.MaxInt32 {
			break
		}
		for j := i + 1; j <= n*2/3; j++ {
			f2, err := strconv.Atoi(S[i+1 : j+1])
			if err != nil || f2 > math.MaxInt32 {
				break
			}

			ans := []int{f1, f2}
			str := S[0 : j+1]
			for len(str) <= n {
				k := len(ans)
				ans = append(ans, ans[k-2]+ans[k-1])
				if ans[k] > math.MaxInt32 {
					break
				}
				str += strconv.Itoa(ans[k])
				if str == S {
					return ans
				}
			}

			if S[i+1] == '0' {
				break
			}
		}
		if S[0] == '0' {
			break
		}
	}
	return []int{}
}
