package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxLength(arr []string) int {
	n := len(arr)
	m := make([]int, n)

	for i := 0; n > 0 && i < n; i++ {
		s := arr[i]
		for j := range s {
			c := int(s[j] - 'a')
			if m[i]&(1<<c) != 0 {
				arr[i], arr[n-1] = arr[n-1], arr[i]
				m[i] = 0
				n--
				i--
				break
			}
			m[i] |= 1 << c
		}
	}

	ans := 0
	var find func(int, int, int)
	find = func(length int, mask int, idx int) {
		ans = max(ans, length)
		if idx == n {
			return
		}
		if mask&m[idx] == 0 {
			find(length+len(arr[idx]), mask|m[idx], idx+1)
		}
		find(length, mask, idx+1)
	}
	find(0, 0, 0)
	return ans
}
