#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 1504
vector<int> adj[MAXN];
int dp[MAXN][2];
int n;

int f(int i, int j)
{
    int k, temp;
    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j] = 1;
    for (k = 0; k < adj[i].size(); k++) {
        dp[i][j] += f(adj[i][k], 1);
    }
    
    if (i == 0 || j == 1) {
        temp = 0;
        for (k = 0; k < adj[i].size(); k++) {
            temp += f(adj[i][k], 0);
        }
        dp[i][j] = min(dp[i][j], temp);
    }
    return dp[i][j];
}

int main()
{
    int i,j,k,rnt,temp,in;
    while (cin >> n && n) {
        memset(dp, -1, sizeof(dp));
        for (i = 0; i < n; i++) {
            cin >> in;
            adj[in].clear();
            cin >> k;
            for (j = 0; j < k; j++) {
                cin >> temp;
                adj[in].push_back(temp);
            }
        }

        rnt = f(0, 0);
        cout << rnt << endl;
    }
    return 0;
}
