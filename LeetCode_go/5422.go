package main

type SubrectangleQueries struct {
	rect [][]int
}

func Constructor(rectangle [][]int) SubrectangleQueries {
	r := SubrectangleQueries{}
	n := len(rectangle)
	m := len(rectangle[0])
	r.rect = make([][]int, n)
	for i := 0; i < n; i++ {
		r.rect[i] = make([]int, m)
		for j := 0; j < m; j++ {
			r.rect[i][j] = rectangle[i][j]
		}
	}

	return r
}

func (this *SubrectangleQueries) UpdateSubrectangle(row1 int, col1 int, row2 int, col2 int, newValue int) {
	for i := row1; i <= row2; i++ {
		for j := col1; j <= col2; j++ {
			this.rect[i][j] = newValue
		}
	}
}

func (this *SubrectangleQueries) GetValue(row int, col int) int {
	return this.rect[row][col]
}

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * obj := Constructor(rectangle);
 * obj.UpdateSubrectangle(row1,col1,row2,col2,newValue);
 * param_2 := obj.GetValue(row,col);
 */
