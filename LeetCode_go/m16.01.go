package main

func swapNumbers(numbers []int) []int {
	a, b := &numbers[0], &numbers[1]
	*a = *a ^ *b
	*b = *a ^ *b
	*a = *a ^ *b
	return numbers
}
