class Solution {
public:
    int uniquePaths(int m, int n) {
		int paths[m + 1][n + 1];
		
		memset(paths, 0, sizeof(paths));
		paths[0][1] = 1;

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {

				paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
			}
		}
		return paths[m][n];
    }
};

