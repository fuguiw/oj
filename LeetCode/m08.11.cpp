#include <iostream>
using namespace std;

class Solution {
    const int mod = 1000000007;
public:
    int waysToChange(int n) {
        int dp[n+1];
        memset(dp, 0, sizeof(dp));

        int v[] = {1,5,10,25};
        dp[0] = 1;
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= n; j++) {
                if (j >= v[i]) {
                    dp[j] += dp[j - v[i]];
                }
                dp[j] %= mod;
            }
        }

        cout << dp << endl;
        return dp[n];
    }
};

int main() {
    Solution sol;
    cout << sol.waysToChange(10) << endl;
}