package main

import "sort"

func subsetsWithDup(nums []int) [][]int {
	sort.Ints(nums)
	var ans [][]int
	ans = append(ans, []int{})
	pre := 0
	for i, num := range nums {
		n := len(ans)
		j := 0
		if i > 0 && nums[i] == nums[i-1] {
			j = pre
		}
		for ; j < n; j++ {
			ans = append(ans, append(append([]int{}, ans[j]...), num))
		}
		pre = n
	}

	return ans
}
