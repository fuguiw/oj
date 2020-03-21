package main

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func findTheDistanceValue(arr1 []int, arr2 []int, d int) int {
	ans := 0
	for i := 0; i < len(arr1); i++ {
		j := 0
		for j = 0; j < len(arr2); j++ {
			if abs(arr1[i]-arr2[j]) <= d {
				break
			}
		}
		if j == len(arr2) {
			ans++
		}
	}
	return ans
}
