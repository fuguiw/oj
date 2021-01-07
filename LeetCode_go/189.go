package main

func gcd(a, b int) int {
	for a != 0 {
		a, b = b%a, a
	}
	return b
}

func rotate(nums []int, k int) {
	n := len(nums)
	k %= n
	if k == 0 {
		return
	}
	for i, count := 0, gcd(n, k); i < count; i++ {
		pre, cur := nums[i], i
		for ok := true; ok; ok = cur != i {
			next := (cur + k) % n
			nums[next], pre, cur = pre, nums[next], next
		}
	}
}
