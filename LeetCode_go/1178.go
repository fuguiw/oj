package main

import "math/bits"

func convert(word string) int {
	ret := 0
	for i := range word {
		ret |= 1 << (word[i] - 'a')
	}

	return ret
}

func findNumOfValidWords(words []string, puzzles []string) []int {
	masks := make(map[int]int)

	for _, word := range words {
		mask := convert(word)
		if bits.OnesCount(uint(mask)) <= 7 {
			masks[mask]++
		}
	}

	ans := make([]int, len(puzzles))
	for i, puzzle := range puzzles {
		first := 1 << (puzzle[0] - 'a')
		mask := convert(puzzle[1:])
		subset := mask
		for {
			ans[i] += masks[subset|first]
			subset = (subset - 1) & mask
			if subset == mask {
				break
			}
		}
	}

	return ans
}
