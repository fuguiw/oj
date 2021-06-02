package main

func checkSubarraySum(nums []int, k int) bool {
	if len(nums) == 0 {
		return false
	}

	m := make(map[int]bool)
	sum, pre := nums[0], nums[0]
	m[0] = true

	for i := 1; i < len(nums); i++ {
		sum += nums[i]
		t := sum
		if k != 0 {
			t %= k
		}
		if m[t] {
			return true
		}
		if k != 0 {
			pre %= k
		}
		m[pre] = true
		pre = sum
	}

	return false
}
