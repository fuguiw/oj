package main

import "sort"

func peakIndexInMountainArray(arr []int) int {
	return sort.Search(len(arr), func(i int) bool {
		if i == 0 {
			return false
		}
		if i == len(arr)-1 {
			return true
		}
		if arr[i] > arr[i-1] && arr[i] < arr[i+1] {
			return false
		}
		if arr[i] < arr[i-1] && arr[i] > arr[i+1] {
			return true
		}
		return true
	})
}
