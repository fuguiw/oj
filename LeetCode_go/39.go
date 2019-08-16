package main

import "fmt"

func findSum(candidates []int, nums []int, i int, sum int, target int, sums *[][]int) {
	if sum == target {
		*sums = append(*sums, nums)
		return
	}

	if target < sum {
		return
	}

	for ; i < len(candidates); i++ {
		tmp := make([]int, len(nums))
		copy(tmp, nums)
		tmp = append(tmp, candidates[i])
		findSum(candidates, tmp, i, sum+candidates[i], target, sums)
	}
}

func combinationSum(candidates []int, target int) [][]int {
	var sums [][]int
	var nums []int
	findSum(candidates, nums, 0, 0, target, &sums)

	return sums
}

func main() {
	candidates := []int{2, 3, 5}
	sums := combinationSum(candidates, 8)
	fmt.Println(sums)
}
