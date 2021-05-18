package main

func countTriplets(arr []int) int {
	ans := 0
	for i := range arr {
		temp := arr[i]
		for j := i + 1; j < len(arr); j++ {
			temp ^= arr[j]
			if temp == 0 {
				ans += j - i
			}

		}
	}
	return ans
}
