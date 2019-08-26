package main

import "fmt"

func singleNumber(nums []int) int {
	var ones, twos int
	for _, num := range nums {
		ones = ones ^ num & ^twos
		twos = twos ^ num & ^ones
	}
	return ones
}

func main() {
	nums := []int{-2, -2, 1, 1, -3, 1, -3, -3, -4, -2}
	fmt.Println(singleNumber(nums))
}
