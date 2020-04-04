#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int dp[len+1][2];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i - 1];
        }

        return max(dp[len][0], dp[len][1]);
    }
};
