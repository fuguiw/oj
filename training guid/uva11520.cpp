#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAXN 11
char grid[MAXN][MAXN], rnt[MAXN][MAXN];
int n;

int is_valid(int row, int col, int l)
{
    if ((row > 0) && (rnt[row - 1][col] - 'A' == l)) return 0;
    if ((row < n - 1) && (grid[row + 1][col] - 'A' == l)) return 0;
    if ((col > 0) && (rnt[row][col - 1] - 'A' == l)) return 0;
    if ((col < n - 1) && (grid[row][col + 1] - 'A' == l)) return 0;
    return 1;
}

int f(int row, int col, int l) 
{
    int i;
    if (!is_valid(row,col,l)) return 0;
    rnt[row][col] = 'A' + l;
    if (row == n - 1 && col == n - 1) return 1;
    if (col == n - 1) {row++; col = 0;}
    else col++;
    if (grid[row][col] != '.') return f(row, col, grid[row][col] - 'A');
    for (i = 0; i < 26; i++) {
        if (f(row, col, i)) return 1;
    }
    return 0;
}

int main()
{
    int t,kase,i;
    cin >> t;
    for (kase = 1; kase <= t; kase++) {
        memset(rnt, 0, sizeof(rnt));
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> grid[i];

        if (grid[0][0] != '.') 
            f(0, 0, grid[0][0] - 'A');
        else 
            for (i = 0; i < 26; i++)
                if (f(0,0,i)) 
                    break;
        printf("Case %d:\n", kase);
        for (i = 0; i < n; i++)
            cout << rnt[i] << endl;
    }
    return 0;
}
