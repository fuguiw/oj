package main

func numSubarrayProductLessThanK(nums []int, k int) int {
	ans := 0

	begin, p := 0, 1
	for i := 0; i < len(nums); i++ {
		p *= nums[i]

		for p >= k && begin <= i {
			p /= nums[begin]
			begin++
		}

		ans += i - begin + 1
	}

	return ans
}
