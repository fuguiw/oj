#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 100004

int n, rnt;
vector<int> adj[MAXN];
int vis[MAXN], subset[MAXN];

int dfs(int i, int flag)
{
    int j, s = 0;
    vis[i] = 1;
    for (j = 0; j < adj[i].size(); j += 2) {
        if (vis[adj[i][j]]) continue;
        if (adj[i][j + 1] == 2) s += dfs(adj[i][j], 1);
        else s += dfs(adj[i][j], 0);
    }
    if (flag && !s) {subset[rnt++] = i; return 1;}
    return s;
}

int main()
{
    int i, a, b, t;
    while (cin >> n) {
        memset(vis, 0, sizeof(vis));
        memset(subset, 0, sizeof(subset));
        rnt = 0;
        for (i = 1; i <= n; i++) adj[i].clear();
        for (i = 0; i < n - 1; i++) {
            cin >> a >> b >> t;
            adj[a].push_back(b);
            adj[a].push_back(t);
            adj[b].push_back(a);
            adj[b].push_back(t);
        }
        dfs(1, 0);
        cout << rnt << endl;
        for (i = 0; i < rnt; i++)
            cout << subset[i] << " ";
        cout << endl;
    }
    return 0;
}

