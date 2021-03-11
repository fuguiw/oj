package main

func calculate(s string) int {
	var nums []int
	var opers []byte
	for i := 0; i < len(s); i++ {
		if s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' {
			opers = append(opers, s[i])
		} else if s[i] == ' ' {
		} else {
			num := 0
			for ; i < len(s) && s[i] >= '0' && s[i] <= '9'; i++ {
				num = num*10 + int(s[i]-'0')
			}
			i--
			if len(opers) != 0 && opers[len(opers)-1] == '*' {
				nums[len(nums)-1] *= num
				opers = opers[:len(opers)-1]
			} else if len(opers) != 0 && opers[len(opers)-1] == '/' {
				nums[len(nums)-1] /= num
				opers = opers[:len(opers)-1]
			} else {
				nums = append(nums, num)
			}
		}
	}
	ans := nums[0]
	for i := range opers {
		if opers[i] == '+' {
			ans += nums[i+1]
		}
		if opers[i] == '-' {
			ans -= nums[i+1]
		}
	}
	return ans
}
