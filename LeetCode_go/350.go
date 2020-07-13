package main

func intersect(nums1 []int, nums2 []int) []int {
	m := make(map[int]int)
	for _, num := range nums1 {
		m[num]++
	}
	var ans []int
	for _, num := range nums2 {
		if m[num] <= 0 {
			continue
		}
		ans = append(ans, num)
		m[num]--
	}
	return ans
}
