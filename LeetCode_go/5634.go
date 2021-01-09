package main

func maximumGain(s string, x int, y int) int {
	ans := 0
	var first, second string
	if x > y {
		first, second = "ab", "ba"
	} else {
		first, second = "ba", "ab"
		x, y = y, x
	}

	cnt := 0
	str := []byte(s)
	for i := 0; i < len(str); i++ {
		if str[i] == first[0] {
			cnt++
		} else if str[i] == first[1] {
			if cnt > 0 {
				ans += x
				str = append(str[:i-1], str[i+1:]...)
				cnt--
				i--
				if i >= 0 {
					i--
				}
			}
		} else {
			cnt = 0
		}
	}
	cnt = 0
	for i := 0; i < len(str); i++ {
		if str[i] == second[0] {
			cnt++
			continue
		} else if str[i] == second[1] {
			if cnt > 0 {
				ans += y
				str = append(str[:i-1], str[i+1:]...)
				i--
				cnt--
				if i >= 0 {
					i--
				}
			}
		} else {
			cnt = 0
		}
	}

	return ans
}
