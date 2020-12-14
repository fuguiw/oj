package main

import (
	"sort"
)

func fabs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

type node struct {
	i int
	a int
	b int
}

func stoneGameVI(aliceValues []int, bobValues []int) int {
	n := len(aliceValues)
	d := make([]node, n)
	for i := range d {
		d[i].a = aliceValues[i]
		d[i].b = bobValues[i]
		d[i].i = i
	}

	sort.Slice(d, func(i, j int) bool {
		if d[i].a > d[j].b {
			if d[j].a <= d[i].b {
				return true
			} else {
				d1 := d[i].a - d[j].b
				d2 := d[j].a - d[i].b
				if d1 > d2 {
					return true
				} else if d1 == d2 {
					return d[i].a > d[j].a
				} else {
					return false
				}
			}
		} else if d[i].a < d[j].b {
			if d[j].a >= d[i].b {
				return false
			} else {
				d1 := d[i].a - d[j].b
				d2 := d[j].a - d[i].b
				if d1 > d2 {
					return true
				} else if d1 == d2 {
					return d[i].a > d[j].a
				} else {
					return false
				}
			}
		} else {
			if d[i].b > d[j].a {
				return true
			} else if d[i].b == d[j].a {
				return d[i].a > d[j].a
			} else {
				return false
			}
		}
	})

	score := 0
	for i := range d {
		if i%2 == 0 {
			score += d[i].a
		} else {
			score -= d[i].b
		}
	}
	if score > 0 {
		return 1
	} else if score == 0 {
		return 0
	} else {
		return -1
	}
}
