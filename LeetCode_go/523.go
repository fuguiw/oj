package main

func checkSubarraySum(nums []int, k int) bool {
	if len(nums) == 0 {
		return false
	}

	m := make(map[int]int)
	sum, pre := nums[0], nums[0]
	m[0] = 1

	for i := 1; i < len(nums); i++ {
		sum += nums[i]
		t := sum
		if k != 0 {
			t %= k
		}
		if m[t] > 0 {
			return true
		}
		if k != 0 {
			pre %= k
		}
		m[pre]++
		pre = sum
	}

	return false
}
