package main

func merge(nums1 []int, m int, nums2 []int, n int) {
	for i := m - 1; i >= 0; i-- {
		nums1[i+n] = nums1[i]
	}

	var i, j, k int
	for i, j, k = 0, n, 0; j < n+m && k < n; i++ {
		if nums1[j] > nums2[k] {
			nums1[i] = nums2[k]
			k++
		} else {
			nums1[i] = nums1[j]
			j++
		}
	}

	for ; k < n; k++ {
		nums1[i] = nums2[k]
		i++
	}
}
