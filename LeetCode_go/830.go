package main

func largeGroupPositions(s string) [][]int {
	var ans [][]int
	for start, end := 0, 0; end <= len(s); end++ {
		if end == len(s) || s[end] != s[start] {
			if end-start >= 3 {
				ans = append(ans, []int{start, end - 1})
			}
			start = end
		}
	}

	return ans
}
