package main

type NumMatrix struct {
	rowsum [][]int
	colsum [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	nm := NumMatrix{}
	if len(matrix) == 0 {
		return nm
	}
	n, m := len(matrix), len(matrix[0])
	nm.rowsum = make([][]int, n+1)
	nm.colsum = make([][]int, n+1)
	for i := 0; i <= n; i++ {
		nm.rowsum[i] = make([]int, m+1)
		nm.colsum[i] = make([]int, m+1)
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			nm.rowsum[i][j] = nm.rowsum[i][j-1] + matrix[i-1][j-1]
			nm.colsum[i][j] = nm.colsum[i-1][j] + matrix[i-1][j-1]
		}
	}
	return nm
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	sum := 0
	n, m := row2-row1, col2-col2
	if n < m {
		for i := row1; i <= row2; i++ {
			sum += this.rowsum[i+1][col2+1] - this.rowsum[i+1][col1]
		}
	} else {
		for j := col1; j <= col2; j++ {
			sum += this.colsum[row2+1][j+1] - this.colsum[row1][j+1]
		}
	}
	return sum
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */
