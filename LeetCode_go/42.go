package main

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func trap(height []int) int {
	result := 0
	for i := 1; i < len(height); i++ {
		if height[i-1] > height[i] {
			continue
		}

		h := 0
		for j := i - 2; j >= 0; j-- {
			if height[j] >= height[i] {
				h = height[i]
				break
			}
			h = max(h, height[j])
		}

		for j := i - 1; j >= 0; j-- {
			if height[j] >= h {
				break
			}
			result += h - height[j]
			height[j] = h
		}
	}

	return result
}
