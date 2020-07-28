package main

func multiply(A int, B int) int {
	if B == 1 {
		return A
	}
	if B == 0 {
		return 0
	}
	if B < 0 {
		return -multiply(A, -B)
	}

	p := multiply(A, B/2)
	p += p
	if B%2 == 1 {
		p += A
	}
	return p
}
