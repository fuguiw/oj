package main

func removeDuplicates(S string) string {
	var st []byte
	for i := range S {
		if len(st) > 0 && st[len(st)-1] == S[i] {
			st = st[:len(st)-1]
		} else {
			st = append(st, S[i])
		}
	}
	return string(st)
}
