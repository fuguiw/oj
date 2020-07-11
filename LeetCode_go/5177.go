package main

import (
	"fmt"
	"strings"
)

func reformatDate(date string) string {
	d := strings.Split(date, " ")

	day := 0
	for i := range d[0] {
		if d[0][i] >= '0' && d[0][i] <= '9' {
			day = day*10 + (int)(d[0][i]-'0')
		}
	}
	m := []string{"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}
	month := 1
	for ; month <= 12; month++ {
		if m[month] == d[1] {
			break
		}
	}

	return fmt.Sprintf("%s-%02d-%02d", d[2], month, day)
}
