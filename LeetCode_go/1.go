package main

func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	for i, n := range nums {
		m[n] = i
	}

	for i := range nums {
		if j, ok := m[target-nums[i]]; ok && i != j {
			return []int{i, j}
		}
	}
	return []int{}
}
