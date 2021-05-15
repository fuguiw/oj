package main

func romanToInt(s string) int {
	nums := []struct {
		roma string
		num  int
	}{
		{"M", 1000},
		{"CM", 900},
		{"D", 500},
		{"CD", 400},
		{"C", 100},
		{"XC", 90},
		{"L", 50},
		{"XL", 40},
		{"X", 10},
		{"IX", 9},
		{"V", 5},
		{"IV", 4},
		{"I", 1},
	}

	i := 0
	ans := 0
	for j := 0; j < len(s); {
		if len(nums[i].roma)+j > len(s) {
			i++
			continue
		}
		if string(s[j:j+len(nums[i].roma)]) == nums[i].roma {
			ans += nums[i].num
			j += len(nums[i].roma)
		} else {
			i++
		}
	}
	return ans
}
