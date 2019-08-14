package LeetCode_go

import (
	"fmt"
	"math"
)

func countBinarySubstrings(s string) int {
	if len(s) == 0 {
		return 0
	}

	prec := s[0]
	pren := 0
	n := 0
	result := 0

    for i := 0; i < len(s); i++ {
    	c := s[i]
		if prec == c {
            n++
		} else {
			if pren > n {
				result += n
			} else {
				result += pren
			}

			prec = c
			pren = n
			n = 1
		}
	}

	if pren > n {
		result += n
	} else {
		result += pren
	}

	return result;
}
