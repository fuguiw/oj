package main

func predictPartyVictory(senate string) string {
	rc, dc := 0, 0
	for i := range senate {
		if senate[i] == 'R' {
			rc++
		} else {
			dc++
		}
	}

	b := make([]bool, len(senate))
	for rc != 0 && dc != 0 {
		r, d := 0, 0
		for i := range senate {
			if b[i] {
				continue
			}
			if senate[i] == 'R' {
				if d > 0 {
					d--
					rc--
					b[i] = true
				} else {
					r++
				}
			} else if senate[i] == 'D' {
				if r > 0 {
					r--
					dc--
					b[i] = true
				} else {
					d++
				}
			}
		}
		for i := range senate {
			if b[i] {
				continue
			}
			if r > 0 && senate[i] == 'D' {
				r--
				dc--
				b[i] = true
			}
			if d > 0 && senate[i] == 'R' {
				d--
				rc--
				b[i] = true
			}
		}
	}
	if rc == 0 {
		return "Dire"
	}
	return "Radiant"
}
