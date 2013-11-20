#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 1004

vector<int> adj[MAXN];
int vis[MAXN][2], dp[MAXN][2];
int n, m;

int f(int i, int j, int k)
{
    int temp, l;
    if (vis[i][j]) return dp[i][j];
    vis[i][j] = 1;

    dp[i][j] = 2000;
    for (l = 0; l < adj[i].size(); l++) {
        if (adj[i][l] != k) {
            dp[i][j] += f(adj[i][l], 1, i);
        }
    }
    if (!j && k != -1) dp[i][j]++;

    if (j || k == -1) {
        temp = 0;
        for (l = 0; l < adj[i].size(); l++) {
            if (adj[i][l] != k) {
                temp += f(adj[i][l], 0, i);
            }
        }
        if (k != -1) temp++;
        dp[i][j] = min(dp[i][j], temp);
    }

    return dp[i][j];
}

int main()
{
    int t, i, rnt, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (i = 0; i < n; i++) adj[i].clear();
        for (i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        memset(vis, 0, sizeof(vis));
        rnt = 0;
        for (i = 0; i < n; i++) {
            if (!vis[i][0])
                rnt += f(i, 0, -1);
        }
        printf("%d %d %d\n", rnt / 2000, m - rnt % 2000, rnt % 2000);
    }
    return 0;
}
