package main

import "fmt"

func dfs(nums []int, pos int, d int, oneNum int, lead bool, limit bool) int {
	if pos == 0 {
		return 1
	}

	up := 9
	if limit {
		up = nums[pos-1]
	}

	ans := 0
	for i := 0; i <= up; i++ {
		nextLead := lead && (i == 0)
		nextLimit := limit && (i == up)
		nextOneNum := oneNum
		if nextLead && d == 0 {
		} else {
			if i == d {
				nextOneNum += 1
			}
		}
		ans += dfs(nums, pos-1, d, nextOneNum, nextLead, nextLimit)
	}

	return ans
}

func find(d int, n int) int {
	nums := make([]int, 11)
	len := 0
	for n != 0 {
		nums[len] = n % 10
		len++
		n /= 10
	}
	fmt.Println(nums)

	return dfs(nums, len, d, 0, true, true)
}

func digitsCount(d int, low int, high int) int {
	return find(d, high) - find(d, low-1)
}
