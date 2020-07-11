package main

import (
	"fmt"
	"sort"
)

func rangeSum(nums []int, n int, left int, right int) int {
	const mod int = 1000000007
	var ns []int

	sum := make([]int, n+1)
	for i := 1; i <= n; i++ {
		sum[i] = sum[i-1] + nums[i-1]
	}

	for i := 0; i < n; i++ {
		for j := i + 1; j <= n; j++ {
			ns = append(ns, sum[j]-sum[i])
		}
	}

	sort.Ints(ns)
	fmt.Println(ns)
	ans := 0
	for ; left <= right; left++ {
		ans = (ans + ns[left-1]) % mod
	}

	return ans
}
