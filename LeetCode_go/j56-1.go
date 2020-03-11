package main

func singleNumbers(nums []int) []int {
	x := 0
	for _, num := range nums {
		x ^= num
	}

	var y int
	for y = 1; x&y == 0; y = y << 1 {
	}

	a, b := 0, 0
	for _, num := range nums {
		if num&y == 0 {
			a ^= num
		} else {
			b ^= num
		}
	}
	return []int{a, b}
}
