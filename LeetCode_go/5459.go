package main

func minNumberOperations(target []int) int {
	ans := 0
	pre := 0
	for _, num := range target {
		if num > pre {
			ans += num - pre
		}
		pre = num
	}
	return ans
}
