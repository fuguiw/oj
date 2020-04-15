#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> ans;
        int dp[n+1][m+1];
        int move[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        memset(move, 0, sizeof(move));

        dp[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (obstacleGrid[i-1][j-1] == 1) {
                    continue;
                }
                if (dp[i-1][j] != 0) {
                    dp[i][j] = dp[i-1][j] + 1;
                    move[i][j] = -1;
                }
                if (dp[i][j-1] != 0) {
                    if (dp[i][j] == 0 || dp[i][j] > dp[i][j-1] + 1) {
                        dp[i][j] = dp[i][j-1] + 1;
                        move[i][j] = 1;
                    }
                }
            }
        }

        ans.push_back(vector<int>{n-1, m-1});
        if (obstacleGrid[n-1][m-1] == 1) {
            return vector<vector<int>>();
        }
        for (int i = n, j = m; i != 1 || j != 1; ) {
            if (move[i][j] == 1) {
                j--;
            } else if (move[i][j] == -1) {
                i--;
            } else {
                return vector<vector<int>>();
            }

            if (obstacleGrid[i-1][j-1] == 1) {
                return vector<vector<int>>();
            }
            ans.insert(ans.begin(), vector<int>{i-1, j-1});
        }
        return ans;
    }
};
