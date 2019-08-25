package main

func singleNumber(nums []int) []int {
	mask := 0
	for _, num := range nums {
		mask ^= num
	}

	mask = mask & (-mask)

	var a, b int
	for _, num := range nums {
		if num&mask != 0 {
			a ^= num
		} else {
			b ^= num
		}
	}

	return []int{a, b}
}
