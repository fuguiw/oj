package main

import "sort"

func intToRoman(num int) string {
	m := map[int]string{
		1:    "I",
		4:    "IV",
		5:    "V",
		9:    "IX",
		10:   "X",
		40:   "XL",
		50:   "L",
		90:   "XC",
		100:  "C",
		400:  "CD",
		500:  "D",
		900:  "CM",
		1000: "M",
	}
	var nums []int
	for k := range m {
		nums = append(nums, k)
	}
	sort.Sort(sort.Reverse(sort.IntSlice(nums)))

	var ans string
	i := 0
	for num != 0 {
		for i < len(nums) {
			if num < nums[i] {
				i++
				continue
			}
			ans += m[nums[i]]
			num -= nums[i]
			break
		}
	}

	return ans
}
