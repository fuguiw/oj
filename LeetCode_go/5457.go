package main

const mod int = 1000000007

func numOfSubarrays(arr []int) int {
	even, odd := 0, 0
	ans := 0
	for _, num := range arr {
		if num%2 == 1 {
			odd, even = even+1, odd
		} else {
			odd, even = odd, even+1
		}
		ans = (ans + odd) % mod
	}
	return ans
}
