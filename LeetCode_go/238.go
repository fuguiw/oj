package main

func productExceptSelf(nums []int) []int {
	products := make([]int, len(nums))
	if len(nums) == 0 {
		return products
	}

	product := 1
	for i := 0; i < len(nums); i++ {
		products[i] = product
		product *= nums[i]
	}

	product = nums[len(nums)-1]
	for i := len(nums) - 2; i >= 0; i-- {
		products[i] = product * products[i]
		product *= nums[i]
	}

	return products
}
