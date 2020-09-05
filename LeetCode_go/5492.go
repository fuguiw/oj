package main

import "fmt"

const mod int = 1000000007

func numWays(s string) int {
	nums := 0
	for i := range s {
		if s[i] == '1' {
			nums++
		}
	}

	ans := 0
	m := make(map[int]int)
	find := func(n int, s string) int {
		if n == 0 {
			return len(s) - 1
		}
		if ret, ok := m[n]; ok {
			return ret
		}

		ret := 0
		c := 0
		for i := 0; i < len(s)-1; i++ {
			if s[i] == '1' {
				c++
			}
			if c == n {
				ret++
			}
		}

		m[n] = ret
		fmt.Println(ret)
		return ret
	}

	n := 0
	for i := 0; i < len(s)-2; i++ {
		if s[i] == '1' {
			n++
			nums--
		}
		if nums%2 == 1 || nums/2 != n {
			continue
		}

		ans = (ans + find(nums/2, s[i+1:])) % mod
	}

	return ans
}
