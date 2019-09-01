package main

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func trap(height []int) int {
	left, right := 0, len(height)-1
	lmax, rmax := 0, 0
	result := 0
	for left < right {
		if height[left] < height[right] {
			if lmax < height[left] {
				lmax = height[left]
			} else {
				result += lmax - height[left]
			}
			left++
		} else {
			if rmax < height[right] {
				rmax = height[right]
			} else {
				result += rmax - height[right]
			}
			right--
		}
	}
	return result
}
