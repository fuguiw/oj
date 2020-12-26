package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maximumBinaryString(binary string) string {
	n := len(binary)
	bi := []byte(binary)
	for i, j := 0, 0; i < n; i++ {
		if bi[i] == '1' {
			continue
		}

		if i+1 < n {
			if bi[i+1] == '0' {
				bi[i] = '1'
			} else {
				for j = max(i+2, j); j < n; j++ {
					if bi[j] == '0' {
						bi[i], bi[i+1], bi[j] = '1', '0', '1'
						j++
						break
					}
				}
			}
		}
	}
	return string(bi)
}
