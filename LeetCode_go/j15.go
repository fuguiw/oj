package main

func hammingWeight(n int) int {
	ans := 0
	for n != 0 {
		n = n & (n - 1)
		ans++
	}
	return ans
}
