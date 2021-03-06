package main

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	return x + y - max(x, y)
}

func beautySum(s string) int {
	ans := 0
	for i := 0; i < len(s); i++ {
		counts := make([]int, 26)
		for j := i; j < len(s); j++ {
			counts[s[j]-'a']++
			minC, maxC := 600, -1
			for _, count := range counts {
				if count == 0 {
					continue
				}
				minC = min(minC, count)
				maxC = max(maxC, count)
			}
			if maxC > minC {
				ans += maxC - minC
			}
		}
	}
	return ans
}
