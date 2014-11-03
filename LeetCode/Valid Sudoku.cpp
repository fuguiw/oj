class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
		bool col[9][10];
		bool row[9][10];
		bool box[9][10];

		memset(col, 0, sizeof(col));
		memset(row, 0, sizeof(row));
		memset(box, 0, sizeof(box));

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.')
					continue;
				int tmp = board[i][j] - '0';
				if (!row[i][tmp]) {
					row[i][tmp] = true;
				} else {
					return false;
				}
				if (!col[j][tmp]) {
					col[j][tmp] = true;
				} else {
					return false;
				}
				int no = (i / 3 * 3) + j / 3;
				if (!box[no][tmp]) {
					box[no][tmp] = true;
				} else {
					return false;
				}
			}
		}
		return true;
    }
};

