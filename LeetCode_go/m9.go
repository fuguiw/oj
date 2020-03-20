package main

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func trap(height []int) int {
	ans := 0
	left, right := -1, -1
	for i, j := 0, len(height)-1; i <= j; {
		if height[i] >= left {
			left = height[i]
			i++
			continue
		}
		if height[j] >= right {
			right = height[j]
			j--
			continue
		}

		if left <= right {
			ans += min(left, right) - height[i]
			//fmt.Println(ans, height[i])
			i++
		} else {
			ans += min(left, right) - height[j]
			//fmt.Println(ans, height[j])
			j--
		}
	}

	return ans
}
