package main

func isMonotonic(A []int) (ans bool) {
	monotonic := func(compare func(x, y int) bool) bool {
		for i := 1; i < len(A); i++ {
			if !compare(A[i-1], A[i]) {
				return false
			}
		}
		return true
	}

	if monotonic(func(x, y int) bool {
		if y >= x {
			return true
		}
		return false
	}) {
		return true
	}

	if monotonic(func(x, y int) bool {
		if y <= x {
			return true
		}
		return false
	}) {
		return true
	}

	return false
}
