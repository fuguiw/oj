package main

func dfs(num []int, d []int, pos int, limit bool) int {
	if !limit && d[pos] != 0 {
		return d[pos]
	}

	if pos == 0 {
		if num[pos] >= 2 {
			return 1
		}
		return 0
	}

	up := 9
	if limit {
		up = num[pos]
	}

	ans := 0
	for i := 0; i <= up; i++ {
		ans += dfs(num, d, pos-1, limit && i == up)
	}
	if up > 2 {
		tmp := 1
		for i := 0; i < pos; i++ {
			tmp = tmp * 10
		}
		ans += tmp
	} else if up == 2 {
		tmp := 0
		for i := pos - 1; i >= 0; i-- {
			tmp = tmp*10 + num[i]
		}
		ans += tmp + 1
	}

	if !limit {
		d[pos] = ans
	}
	return ans
}

func find(n int) int {
	var num []int
	len := 0
	for n > 0 {
		num = append(num, n%10)
		n /= 10
		len++
	}
	d := make([]int, 10)
	d[0] = 1
	return dfs(num, d, len-1, true)
}

func numberOf2sInRange(n int) int {
	return find(n)
}
