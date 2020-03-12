package main

func findContinuousSequence(target int) [][]int {
	var ans [][]int

	seq := []int{1, 2}
	for i, j, sum := 1, 2, 3; i < j && j < target; {
		if sum == target {
			ans = append(ans, seq)
		}
		if sum < target {
			j++
			sum += j
			seq = append(seq, j)
		} else {
			sum -= i
			i++
			seq = seq[1:]
		}
	}

	return ans
}
