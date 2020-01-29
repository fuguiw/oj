package main

import "fmt"

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func findKthNumber(n int, k int) int {
	getCount := func(prefix int) int {
		cur, next := prefix, prefix+1
		count := 0
		for ; cur < n; cur, next = cur*10, next*10 {
			count += min(n+1, next) - cur
		}
		return count
	}
	fmt.Println(getCount(1))

	prefix, next := 1, 1
	for k > 0 {
		prefix = next
		c := getCount(prefix)
		if c >= k {
			k--
			next = prefix * 10
		} else {
			k -= c
			next = prefix + 1
		}
	}

	return prefix
}
