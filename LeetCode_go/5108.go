package main

func encode(num int) string {
	if num == 0 {
		return ""
	}

	for i := 0; i < 32; i++ {
		if num > (1 << i) {
			num -= 1 << i
		}
	}

	var result string

}
