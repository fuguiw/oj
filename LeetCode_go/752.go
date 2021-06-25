package main

import "container/list"

func openLock(deadends []string, target string) int {
	md := make(map[string]bool)
	for _, deadend := range deadends {
		md[deadend] = true
	}

	q := list.New()
	visit := make(map[string]bool)
	q.PushBack("0000")
	q.PushBack(0)
	visit["0000"] = true
	for q.Len() != 0 {
		d := []byte(q.Front().Value.(string))
		q.Remove(q.Front())
		step := q.Front().Value.(int)
		q.Remove(q.Front())
		if string(d) == target {
			return step
		}
		if md[string(d)] {
			continue
		}

		for i := 0; i < 4; i++ {
			c := d[i]
			d[i] = (c-'0'+1)%10 + '0'
			if !visit[string(d)] {
				q.PushBack(string(d))
				q.PushBack(step + 1)
				visit[string(d)] = true
			}
			d[i] = (c-'0'+9)%10 + '0'
			if !visit[string(d)] {
				q.PushBack(string(d))
				q.PushBack(step + 1)
				visit[string(d)] = true
			}
			d[i] = c
		}
	}

	return -1
}
