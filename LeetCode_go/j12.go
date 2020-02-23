package main

func dfs(board [][]byte, word string, x, y int) bool {
	if len(word) == 0 {
		return true
	}

	m := [][]int{
		{0, 1},
		{1, 0},
		{-1, 0},
		{0, -1},
	}

	for k := 0; k < 4; k++ {
		i, j := x+m[k][0], y+m[k][1]
		if i < 0 || i >= len(board) || j < 0 || j >= len(board[i]) {
			continue
		}
		if board[i][j] == word[0] {
			c := board[i][j]
			board[i][j] = ' '
			if dfs(board, word[1:], i, j) {
				return true
			}
			board[i][j] = c
		}
	}
	return false
}

func exist(board [][]byte, word string) bool {
	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[i]); j++ {
			if board[i][j] == word[0] {
				c := board[i][j]
				board[i][j] = ' '
				if dfs(board, word[1:], i, j) {
					return true
				}
				board[i][j] = c
			}
		}
	}
	return false
}
