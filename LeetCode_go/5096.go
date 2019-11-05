package main

func transformArray(arr []int) []int {
	f := true
	tmp := make([]int, len(arr))
	for f {
		f = false
		copy(tmp, arr)
		for i := 1; i < len(arr)-1; i++ {
			if arr[i-1] > arr[i] && arr[i+1] > arr[i] {
				f = true
				tmp[i]++
			}
			if arr[i-1] < arr[i] && arr[i+1] < arr[i] {
				f = true
				tmp[i]--
			}
		}
		arr = tmp
	}

	return arr
}
