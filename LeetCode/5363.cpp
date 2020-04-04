#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));

        sort(satisfaction.begin(), satisfaction.end());

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][1] = satisfaction[i - 1];
            for (int j = 2; j <= i; j++) {
                int tmp = -44444444;
                for (int k = j - 1; k < i; k++) {
                    tmp = max(tmp, dp[k][j - 1]);
                }
                dp[i][j] = tmp + satisfaction[i - 1] * j;

                cout << i << "," << j << endl;
                cout << dp[i][j] << endl;
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};
