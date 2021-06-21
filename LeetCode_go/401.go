package main

import (
	"math/bits"
	"strconv"
)

func readBinaryWatch(turnedOn int) []string {
	var ans []string
	for n := 0; n < 1<<11; n++ {
		if bits.OnesCount(uint(n)) != turnedOn {
			continue
		}
		time := func(n int) string {
			var time string
			hour, minute := 0, 0
			for i := 0; i < 6; i++ {
				if n&(1<<i) != 0 {
					minute += 1 << i
				}
			}
			for i := 0; i < 4; i++ {
				if n&(1<<(i+6)) != 0 {
					hour += 1 << i
				}
			}
			if hour < 12 && minute < 60 {
				if minute < 10 {
					time = strconv.Itoa(hour) + ":0" + strconv.Itoa(minute)
				} else {
					time = strconv.Itoa(hour) + ":" + strconv.Itoa(minute)
				}
			}
			return time
		}(n)
		if len(time) != 0 {
			ans = append(ans, time)
		}
	}

	return ans
}
