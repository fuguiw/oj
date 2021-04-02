package main

func trap(height []int) int {
	n := len(height)
	if n == 0 {
		return 0
	}
	left, right := 0, n-1
	lh, rh := height[left], height[right]
	ans := 0
	for left < right {
		if lh <= rh {
			left++
			if height[left] > lh {
				lh = height[left]
			} else {
				ans += lh - height[left]
			}
		} else {
			right--
			if height[right] > rh {
				rh = height[right]
			} else {
				ans += rh - height[right]
			}
		}
	}
	return ans
}
