#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 100
int dp[MAXN][MAXN], visit[MAXN][MAXN], sum[MAXN][MAXN];
int d[MAXN];

int f(int i, int j)
{
    int x,y;
    if (i > j) return 0;
    if (visit[i][j]) return dp[i][j];
    for (x = i; x <= j; x++) {
        if (!visit[i][j]) {
            visit[i][j] = 1;
            dp[i][j] = sum[i][i] - f(i + 1, j);
            continue;
        }
        dp[i][j] = max(dp[i][j], sum[i][x] - f(x + 1, j));
        dp[i][j] = max(dp[i][j], sum[x][j] - f(i, x - 1));
    }
    visit[i][j] = 1;
    return dp[i][j];
}

int main()
{
    int n,i,j;
    while (cin >> n && n) {
        memset(visit, 0, sizeof(visit));
        for (i = 0; i < n; i++) {cin >> d[i]; sum[i][i] = d[i];}
        for (i = 0; i < n; i++) 
            for (j = i + 1; j < n; j++)
                sum[i][j] = sum[i][j - 1] + d[j];
        f(0, n - 1);
        cout << dp[0][n - 1] << endl;
    }
}
