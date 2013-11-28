#include <iostream>
using namespace std;
#define MAXN 104
int grid[MAXN][MAXN], pre[MAXN][MAXN];
int n, m, x;

int cnt(int x, int y)
{
    int i, j, tx, ty, c = 0;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            tx = (x + i + n) % n;
            ty = (y + j + m) % m;
            if (pre[tx][ty]) c++;
        }
    }
    return c;
}

void f()
{
    int c, i, j;
    for (i = 0 ; i < n; i++) {
        for (j = 0; j < m; j++) {
            c = cnt(i, j);
            if (c == 3) grid[i][j] = 1;
            else if (c == 2) grid[i][j] = pre[i][j];
            else grid[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            pre[i][j] = grid[i][j];
}

int main()
{
    int i, j;
    while (cin >> n >> m >> x && n) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j ++) {
                cin >> grid[i][j];
                pre[i][j] = grid[i][j];
            }
        }
        for (i = 0; i < x; i++) {
            f();
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
