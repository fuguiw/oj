package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxTurbulenceSize(arr []int) int {
	ans := 0
	a, b := 0, 0
	for i := range arr {
		if i == 0 {
			a, b = 1, 1
			ans = 1
			continue
		}
		if arr[i] == arr[i-1] {
			a, b = 1, 1
		} else if arr[i] > arr[i-1] {
			if i%2 == 1 {
				a, b = a+1, 1
			} else {
				a, b = 1, b+1
			}
		} else {
			if i%2 == 1 {
				a, b = 1, b+1
			} else {
				a, b = a+1, 1
			}
		}
		ans = max(ans, max(a, b))
	}
	return ans
}
