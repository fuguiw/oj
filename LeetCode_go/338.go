package main

func countBits(num int) []int {
	ans := make([]int, num+1)
	highBit := 0
	for i := 1; i <= num; i++ {
		if i&(i-1) == 0 {
			highBit = i
		}
		ans[i] = ans[i-highBit] + 1
	}
	return ans
}
