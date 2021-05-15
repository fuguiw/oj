package main

func rotateTheBox(box [][]byte) [][]byte {
	n, m := len(box), len(box[0])
	ans := make([][]byte, m)
	for i := range ans {
		ans[i] = make([]byte, n)
	}

	for i := range box {
		for j := range box[i] {
			ans[j][n-1-i] = box[i][j]
		}
	}

	for j := 0; j < n; j++ {
		pre := m
		for i := m - 1; i >= 0; i-- {
			if ans[i][j] == '#' {
				pre--
				ans[pre][j] = '#'
				if pre != i {
					ans[i][j] = '.'
				}
			} else if ans[i][j] == '*' {
				pre = i
			}
		}
	}

	return ans
}
