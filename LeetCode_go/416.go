package main

func canPartition(nums []int) bool {
	sum := 0
	for _, num := range nums {
		sum += num
	}

	if sum%2 == 1 {
		return false
	}
	sum /= 2

	d := make([]int, sum+1)
	for _, num := range nums {
		for i := sum - num; i >= 0; i-- {
			if d[i] == 1 {
				d[i+num] = 1
			}
		}
		if num <= sum {
			d[num] = 1
		}
	}

	return d[sum] == 1
}
