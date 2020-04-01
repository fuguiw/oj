package main

import "sort"

func threeSum(nums []int) [][]int {
	ans := make([][]int, 0)
	if len(nums) < 3 {
		return ans
	}

	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})

	for i := range nums {
		if nums[i] > 0 {
			return ans
		}
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		for l, r := i+1, len(nums)-1; l < r; {
			if nums[i]+nums[l]+nums[r] == 0 {
				ans = append(ans, []int{nums[i], nums[l], nums[r]})
				for ; l < r; l++ {
					if nums[l+1] != nums[l] {
						break
					}
				}
				for ; l < r; r-- {
					if nums[r-1] != nums[r] {
						break
					}
				}
				l, r = l+1, r-1
			} else {
				if nums[i]+nums[l]+nums[r] > 0 {
					r--
				} else {
					l++
				}
			}
		}
	}

	return ans
}
