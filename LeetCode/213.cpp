#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        int dp[len+1][2];

        int ans = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 2; i <= len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i - 1];
        }
        ans = max(dp[len][0], dp[len][1]);

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i - 1];
        }
        ans = max(ans, dp[len][0]);

        return ans;
    }
};
