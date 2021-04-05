package main

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func orchestraLayout(num int, xPos int, yPos int) int {
	level := min(xPos, num-xPos-1)
	level = min(level, min(yPos, num-yPos-1))

	ans := 0
	ans = (num*2 - 2*level) * level / 2 * 4 % 9
	ans = (ans + 8) % 9
	l := num - level*2

	if xPos == level {
		ans = (ans + (yPos - level + 1)) % 9
		return ans + 1
	}
	ans = (ans + (l - 1)) % 9
	if yPos == num-1-level {
		ans = (ans + xPos - level + 1) % 9
		return ans + 1
	}
	ans = (ans + (l - 1)) % 9

	if xPos == num-1-level {
		ans = (ans + (num - level - yPos)) % 9
		return ans + 1
	}
	ans = (ans + (l - 1)) % 9
	ans = (ans + (num - level - xPos)) % 9
	return ans + 1
}
