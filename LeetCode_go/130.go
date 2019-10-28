package main

func foo(board [][]byte, x, y int) {
	if x < 0 || x >= len(board) || y < 0 || y >= len(board[x]) || board[x][y] != 'O' {
		return
	}

	board[x][y] = 'o'
	foo(board, x-1, y)
	foo(board, x+1, y)
	foo(board, x, y-1)
	foo(board, x, y+1)
}

func solve(board [][]byte) {
	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[i]); j++ {
			if i == 0 || i == len(board)-1 || j == 0 || j == len(board[i])-1 {
				foo(board, i, j)
			}
		}
	}

	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[i]); j++ {
			if board[i][j] == 'O' {
				board[i][j] = 'X'
			}
			if board[i][j] == 'o' {
				board[i][j] = 'O'
			}
		}
	}
}
