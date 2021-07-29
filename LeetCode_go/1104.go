package main

func pathInZigZagTree(label int) []int {
	var ans []int
	for ; label > 0; label /= 2 {
		ans = append([]int{label}, ans...)
	}
	for i := len(ans) - 1; i > 0; i -= 2 {
		left, right := 1<<i, 1<<(i+1)-1
		ans[i] = right - (ans[i] - left)
	}

	return ans
}
