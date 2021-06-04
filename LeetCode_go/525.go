package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func findMaxLength(nums []int) int {
	m := make(map[int]int)
	n := 0
	m[0] = -1
	ans := 0
	for i, num := range nums {
		n += num
		if num == 0 {
			n -= 1
		}
		if _, ok := m[n]; ok {
			ans = max(ans, i-m[n])
		}
		if _, ok := m[n]; !ok {
			m[n] = i
		}
	}
	return ans
}
