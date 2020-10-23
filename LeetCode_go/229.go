package main

func majorityElement(nums []int) []int {
	cand1, cand2 := nums[0], nums[0]
	count1, count2 := 0, 0
	for _, num := range nums {
		if num == cand1 {
			count1++
			continue
		}
		if num == cand2 {
			count2++
			continue
		}
		if count1 == 0 {
			cand1 = num
			count1++
			continue
		}
		if count2 == 0 {
			cand2 = num
			count2++
			continue
		}
		count1--
		count2--
	}

	var ans []int
	count1, count2 = 0, 0
	for _, num := range nums {
		if num == cand1 {
			count1++
		}
		if num == cand2 {
			count2++
		}
	}
	if count1 > len(nums)/3 {
		ans = append(ans, cand1)
	}
	if cand1 != cand2 && count2 > len(nums)/3 {
		ans = append(ans, cand2)
	}

	return ans
}
