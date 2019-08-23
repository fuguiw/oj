package main

func sortColors(nums []int) {
	m := make(map[int]int)

	for _, num := range nums {
		m[num]++
	}

	index := 0
	for i := 0; i < 3; i++ {
		for ; m[i] > 0; m[i]-- {
			nums[index] = i
			index++
		}
	}
}
