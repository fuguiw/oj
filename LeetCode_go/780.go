package main

func reachingPoints(sx int, sy int, tx int, ty int) bool {
	if tx < sx || ty < sy {
		return false
	}

	if tx < ty {
		if sx == tx {
			return (ty-sy)%sx == 0
		}
		return reachingPoints(sx, sy, tx, ty%tx)
	} else if tx > ty {
		if sy == ty {
			return (tx-sx)%sy == 0
		}
		return reachingPoints(sx, sy, tx%ty, ty)
	} else {
		return sx == tx && sy == ty
	}
}
