package main

func isValidSerialization(preorder string) bool {
	st := []byte{'1'}
	for i := 0; i < len(preorder); i++ {
		if preorder[i] == ',' {
			continue
		}
		if preorder[i] == '#' {
			if len(st) == 0 {
				return false
			}
			st = st[:len(st)-1]
			continue
		}
		for ; i < len(preorder) && preorder[i] >= '0' && preorder[i] <= '9'; i++ {
		}
		i--
		if len(st) == 0 {
			return false
		}
		st = append(st[:len(st)-1], []byte{preorder[i], preorder[i]}...)
	}
	return len(st) == 0
}
