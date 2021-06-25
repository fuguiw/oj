package main

func canIWin(maxChoosableInteger int, desiredTotal int) bool {
	if desiredTotal > (maxChoosableInteger+1)*maxChoosableInteger/2 {
		return false
	}

	visit := make(map[int]bool)
	var find func(int, int) bool
	find = func(choosable int, desired int) bool {
		if _, ok := visit[choosable]; ok {
			return visit[choosable]
		}

		for i := maxChoosableInteger - 1; i >= 0; i-- {
			if choosable&(1<<i) == 0 {
				continue
			}
			if desired-1-i <= 0 {
				visit[choosable] = true
				return true
			}
			if find(choosable^(1<<i), desired-1-i) == false {
				visit[choosable] = true
				return true
			}
		}
		visit[choosable] = false
		return false
	}

	return find((1<<maxChoosableInteger)-1, desiredTotal)
}
