package main

import "strconv"

func smallestGoodBase(n string) string {
	nint, _ := strconv.ParseInt(n, 10, 64)
	var ans string

	valid := func(p int, num uint64) int {
		var sum uint64 = 1
		var pow uint64 = 1
		for i := 1; i <= p; i++ {
			pow *= num
			if i > 1 && pow > 1e18 {
				return 1
			}
			sum += pow
			if sum > uint64(nint) {
				return 1
			}
		}
		if sum == uint64(nint) {
			return 0
		}
		return -1
	}

	find := func(p int) int64 {
		left, right := uint64(2), uint64(nint)-1
		for left <= right {
			mid := (left + right) / 2
			v := valid(p, mid)
			if v == 0 {
				return int64(mid)
			}
			if v < 0 {
				left = mid + 1
			} else {
				right = mid - 1
			}
		}
		return -1
	}

	for i := 1; i <= 64; i++ {
		base := find(i)
		if base != -1 {
			ans = strconv.FormatInt(base, 10)
		}
	}

	return ans
}
