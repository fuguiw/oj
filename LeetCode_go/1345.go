package main

func minJumps(arr []int) int {
	n := len(arr)
	m := make(map[int][]int)
	for i, num := range arr {
		m[num] = append(m[num], i)
	}

	q := []int{0, 0}
	visit := make([]int, n)
	visit[0] = 1
	for len(q) != 0 {
		i, step := q[0], q[1]
		q = q[2:]
		if i == n-1 {
			return step
		}

		if i > 0 && visit[i-1] == 0 {
			q = append(q, []int{i - 1, step + 1}...)
			visit[i-1] = 1
		}
		if i < n-1 && visit[i+1] == 0 {
			q = append(q, []int{i + 1, step + 1}...)
			visit[i+1] = 1
		}

		for _, j := range m[arr[i]] {
			if visit[j] == 0 {
				q = append(q, []int{j, step + 1}...)
				visit[j] = 1
			}
		}
		m[arr[i]] = []int{}
	}

	return 0
}
