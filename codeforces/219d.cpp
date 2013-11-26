#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAXN 200004
int rnt[MAXN], cnt[MAXN], vis[MAXN];
vector<int> adj[MAXN];
int n;

int f(int i, int p)
{
    int temp = 0, j;
    for (j = 0; j < adj[i].size(); j += 2) {
        if (adj[i][j] == p) continue;
        temp += f(adj[i][j], i) + adj[i][j + 1];
    }
    return temp;
}


void f2(int i)
{
    int j;
    for (j = 0; j < adj[i].size(); j += 2) {
        if (vis[adj[i][j]]) continue;
        if (adj[i][j + 1] == 0) rnt[adj[i][j]] = rnt[i] + 1;
        else rnt[adj[i][j]] = rnt[i] - 1;
        vis[adj[i][j]] = 1;
        f2(adj[i][j]);
    }
}

int main()
{
    int s, t, m, i, j, cnt;
    while (cin >> n) {
        m = MAXN;
        memset(vis, 0 ,sizeof(vis));
        for (i = 1; i <= n; i++) adj[i].clear();
        for (i = 0; i < n - 1; i++) {
            cin >> s >> t;
            adj[s].push_back(t);
            adj[s].push_back(0);
            adj[t].push_back(s);
            adj[t].push_back(1);
        }

        rnt[1] = f(1, -1);
        m = min(m, rnt[1]);
        vis[1] = 1;
        cnt = 1;

        f2(1);

        for (i = 1; i <= n; i++) 
            m = min(m, rnt[i]);

        cout << m << endl;
        for (i = 1; i <= n; i++) 
            if (rnt[i] == m)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}
