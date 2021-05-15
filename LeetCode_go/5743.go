package main

func memLeak(memory1 int, memory2 int) []int {
	crash := make([]int, 3)
	crash[1], crash[2] = memory1, memory2

	for time := 1; ; time++ {
		if crash[1] >= crash[2] {
			if crash[1] < time {
				crash[0] = time
				break
			}
			crash[1] -= time
		} else {
			if crash[2] < time {
				crash[0] = time
				break
			}
			crash[2] -= time
		}
	}

	return crash
}
