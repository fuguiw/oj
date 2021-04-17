package main

func getMaximumXor(nums []int, maximumBit int) []int {
	n := len(nums)
	ans := make([]int, len(nums))
	maxn := 1<<maximumBit - 1
	N := 0
	for _, num := range nums {
		N ^= num
	}
	for i := n - 1; i >= 0; i-- {
		ans[n-i-1] = maxn ^ N
		N ^= nums[i]
	}

	return ans
}
