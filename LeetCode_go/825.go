package main

import "fmt"

func numFriendRequests(ages []int) int {
	m := make([]int, 121)

	for _, age := range ages {
		m[age]++
	}
	for i := 1; i < 121; i++ {
		m[i] += m[i-1]
	}
	fmt.Println(m)

	ans := 0
	for _, age := range ages {
		left, right := age/2+7, age
		if left >= right {
			continue
		}
		ans += m[right] - m[left]
		if age > left && age <= right {
			ans--
		}
	}

	return ans
}
