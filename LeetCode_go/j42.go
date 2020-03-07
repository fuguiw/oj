package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxSubArray(nums []int) int {
	ans, s := -10000, 0
	for _, num := range nums {
		s = max(s+num, num)
		ans = max(s, ans)
	}
	return ans
}
