#include <iostream>
using namespace std;
#define MAXN 501
char maze[MAXN][MAXN];
int n, m, k;

void f(int r, int c)
{
    if (maze[r][c] != 1) return;
    maze[r][c] = '.';
    if (r > 0 && maze[r - 1][c] == 1) f(r - 1, c);
    if (c > 0 && maze[r][c - 1] == 1) f(r, c - 1);
    if (r < n - 1 && maze[r + 1][c] == 1) f(r + 1, c);
    if (c < m - 1 && maze[r][c + 1] == 1) f(r, c + 1);
    if (k) {maze[r][c] = 'X'; k--;}
}

int main()
{
    int i, j, r, c;
    while (cin >> n >> m >> k) {
        for (i = 0; i < n; i++) cin >> maze[i];
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                if(maze[i][j] == '.')
                    maze[r = i][c = j] = 1;
        for (f(r, c), i = 0; i < n; i++)
            cout << maze[i] << endl;
    }
    return 0;
}
