package main

func find(s string, ans *[]string, idx int, m *map[string]bool) {
	if idx == len(s) {
		if (*m)[s] {
			return
		}
		*ans = append(*ans, s)
		(*m)[s] = true
		return
	}

	for i := idx; i < len(s); i++ {
		tmp := []byte(s)
		tmp[i], tmp[idx] = tmp[idx], tmp[i]
		find(string(tmp), ans, idx+1, m)
	}
}

func permutation(s string) []string {
	var ans []string
	m := make(map[string]bool)
	find(s, &ans, 0, &m)
	return ans
}
