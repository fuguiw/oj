package main

func subarraySum(nums []int, k int) int {
	sums := make(map[int]int)

	result := 0
	sum := 0
	sums[0] = 1
	for _, num := range nums {
		sum += num
		result += sums[sum-k]
		sums[sum]++
	}

	return result
}
