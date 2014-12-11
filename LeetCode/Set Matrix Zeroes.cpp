class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
		int n, m;
		int i, j;
		int row, col;

		n = matrix.size();
		m = matrix[0].size();
		row = col = 1;

		for (i = 0; i < n; i++) col &&= matrix[i][0];
		for (i = 0; i < m; i++) row &&= matrix[0][i];

		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (matrix[i][j] == 0) {
					matrix[0][j] = matrix[i][0] = 0;
				}
			}
		}

		for (i = 1; i < n; i++) {
			for (j = 1; j < m; j++) {
				if (!matrix[0][j] || !matrix[i][0])
					matrix[i][j] = 0;
			}
		}

		if (!col)
			for (i = 0; i < n; i++)
				matrix[i][0] = 0;

		if (!row)
			for (i = 0; i < m; i++)
				matrix[0][i] = 0;
    }
};

