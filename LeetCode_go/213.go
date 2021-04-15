package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func rob(nums []int) int {
	n := len(nums)
	if n == 1 {
		return nums[0]
	}
	if n == 2 {
		return max(nums[0], nums[1])
	}
	find := func(nums []int) int {
		a, b, ans := 0, 0, 0
		for _, num := range nums {
			a, b = b+num, max(a, b)
			ans = max(ans, max(a, b))
		}
		return ans
	}

	return max(find(nums[1:]), find(nums[2:n-1])+nums[0])
}
