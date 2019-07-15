package main

import (
	"bytes"
	"fmt"
	"strconv"
)

var count int
var result string

func permute(nums []int, i int, k int) {
	if i == len(nums) {
		count++
		if count > k {
			return
		} else if count == k {
			var r bytes.Buffer
			for _, n := range nums {
				r.WriteString(strconv.Itoa(n))
			}
			result = r.String()
		}
		return
	}

	newNums := make([]int, len(nums), len(nums))
	copy(newNums, nums)

	for j := i; j < len(nums); j++ {
		newNums[i], newNums[j] = newNums[j], newNums[i]
		permute(newNums, i+1, k)
	}
}

func getPermutation(n int, k int) string {

	nums := make([]int, n, n)
	for i := 0; i < n; i++ {
		nums[i] = i + 1
	}

	permute(nums, 0, k)
	return result
}

func main() {
	str := getPermutation(4, 9)
	fmt.Println(str)
}
