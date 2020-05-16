package main

import (
	"fmt"
	"strconv"
)

func largestNumber(cost []int, target int) string {
	d := make([]string, target+1)

	var find func([]int, int) string
	find = func(cost []int, target int) string {
		if len(d[target]) != 0 {
			return d[target]
		}
		ans := "0"
		for i := 9; i >= 1; i-- {
			fmt.Println(i)
			if cost[i-1] == target {
				t := strconv.Itoa(i)
				if len(ans) < len(t) || ans < t {
					ans = t
				}
				continue
			}
			if cost[i-1] > target {
				continue
			}
			t := find(cost, target-cost[i-1])
			if t != "0" {
				t = strconv.Itoa(i) + t
				if len(ans) < len(t) || ans < t {
					ans = t
				}
			}
		}

		d[target] = ans
		return ans
	}
	return find(cost, target)
}
