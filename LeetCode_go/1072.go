package main

import (
	"bytes"
	"strconv"
)

func toString(row []int) string {
	var buffer bytes.Buffer
	for _, n := range row {
		buffer.WriteString(strconv.Itoa(n))
	}
	return buffer.String()
}

func toStringOppo(row []int) string {
	var buffer bytes.Buffer
	for _, n := range row {
		buffer.WriteString(strconv.Itoa(1 - n))
	}
	return buffer.String()
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxEqualRowsAfterFlips(matrix [][]int) int {
	m := make(map[string]int)
	for _, row := range matrix {
		m[toString(row)]++
		m[toStringOppo(row)]++
	}

	ans := 0
	for _, row := range matrix {
		ans = max(ans, m[toString(row)]+m[toStringOppo(row)])
	}

	return ans
}
