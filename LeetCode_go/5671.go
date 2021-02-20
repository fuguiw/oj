package main

import "container/list"

func highestPeak(isWater [][]int) [][]int {
	n, m := len(isWater), len(isWater[0])
	ans := make([][]int, n)
	for i := range ans {
		ans[i] = make([]int, m)
	}

	visit := make([][]bool, n)
	for i := range visit {
		visit[i] = make([]bool, m)
	}
	q := list.New()
	mx := []int{-1, 1, 0, 0}
	my := []int{0, 0, 1, -1}
	for i := range isWater {
		for j := range isWater[i] {
			if isWater[i][j] == 1 {
				visit[i][j] = true
				q.PushBack(i)
				q.PushBack(j)
				q.PushBack(ans[i][j])
			}
		}
	}

	for q.Len() != 0 {
		i := q.Front().Value.(int)
		q.Remove(q.Front())
		j := q.Front().Value.(int)
		q.Remove(q.Front())
		h := q.Front().Value.(int)
		q.Remove(q.Front())

		for k := 0; k < 4; k++ {
			nx, ny := i+mx[k], j+my[k]
			if nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny] {
				continue
			}
			visit[nx][ny] = true
			ans[nx][ny] = h + 1
			q.PushBack(nx)
			q.PushBack(ny)
			q.PushBack(ans[nx][ny])
		}
	}

	return ans
}
