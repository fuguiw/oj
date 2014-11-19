class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
		int n;
		int m;
		int i, j;

		if (!(n = grid.size()))
			return 0;
		m = grid[0].size();

		int sum[m];
		memset(sum, 0, sizeof(sum));
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (!j) {
					sum[j] = sum[j] + grid[i][j];
				} else if (!i) {
					sum[j] = sum[j - 1] + grid[i][j];
				} else {
					sum[j] = min(sum[j], sum[j - 1]) + grid[i][j];
				}
			}
		}
		return sum[m - 1];
    }
};

