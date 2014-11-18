class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		int len = triangle.size();
		int rnt = 0;
		int dp[len];
		int i, j;

		if (!len)
			return 0;

		dp[0] = triangle[0][0];
		for (i = 1; i < len; i++) {
			dp[i] = dp[i - 1] + triangle[i][i];
			for (j = i - 1; j > 0; j--) {
				dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
			}
			dp[j] = dp[j] + triangle[i][0];
		}

		rnt = dp[0];
		for (i = 1; i < len; i++)
			rnt = min(rnt, dp[i]);
		return rnt;
    }
};

