#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) {
            return 0;
        }

        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        for (int j = 0; j < n; j++) {
            dp[j][j] = 1;
            for (int i = j - 1; i >= 0; i--) {
                dp[i][j] = j - i + 1;

                if (i + 1 == j) {
                    dp[i][j] = arr[i] == arr[j] ? 1 : 2;
                    continue;
                }

                if (arr[i] == arr[j]) {
                    dp[i][j] = dp[i+1][j-1];
                }
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }

        return dp[0][n-1];
    }
};
