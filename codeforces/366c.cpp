#include <iostream>
#include <cstring>
using namespace std;
int dp[101][200000];
int c[101], t[101];

int main()
{
    int n, k, i, j, m;
    while (cin >> n >> k) {
        for (i = 1; i <= n; i++) cin >> t[i];
        for (i = 1; i <= n; i++) cin >> c[i];
        m = 1000 * n;
        memset(dp, 128, sizeof(dp));
        dp[0][m] = 0;
        for (i = 1; i <= n; i++) {
            for (j = 2 * m; j >= 0; j--) {
                dp[i][j] = max(dp[i - 1][j - t[i] + c[i] * k] + t[i], dp[i - 1][j]);
            }
        }
        if (dp[n][m]) cout << dp[n][m] << endl;
        else cout << "-1" << endl;
    }
    return 0;
}
