func maxEqualFreq(nums []int) int {
	mn := make(map[int]int)
	mc := make(map[int]int)
	ans := 0
	for i, num := range nums {
		count := mn[num]
		mc[count]--
		if mc[count] <= 0 {
			delete(mc, count)
		}

		mn[num]++
		count = mn[num]
		mc[count]++
		//fmt.Println(mc)
		if len(mc) < 2 {
			for key, value := range mc {
				if value == 1 || key == 1 {
					ans = i
				}
			}
		} else if len(mc) == 2 {
			var c, n []int
			for key, value := range mc {
				c = append(c, key)
				n = append(n, value)
			}
            if c[0] == 1 && n[0] == 1 || c[1] == 1 && n[1] == 1 {
				ans = i
			}
            if (n[0] == 1 && c[0] - c[1] == 1) || (n[1] == 1 && c[1] - c[0] == 1) {
                ans = i
            }
		}
	}

	return ans+1
}
