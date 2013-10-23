#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstdio>
using namespace std;
int ma[17][17],mb[17][17];
int rnt,n;

int is_even(int row, int col) 
{
    int cnt = 0;
    if (row - 1 >= 1) cnt += mb[row - 1][col];
    //if (row + 1 <= n) cnt += mb[row + 1][col];
    if (col - 1 >= 1) cnt += mb[row][col - 1];
    if (col + 1 <= n) cnt += mb[row][col + 1];
    return (1 - cnt % 2);
}

void f(int row, int col, int cnt)
{
    if (n == 1) {rnt = 0; return ;}
    if (row == n) {
        //cout << row << " " << rnt << endl;
        if (is_even(row - 1, col)) {
            if (ma[row][col] == 1) return;
            mb[row][col] = 0;
            if (col > 1 && !is_even(row, col - 1)) return;
            if (col == n) {rnt = min(rnt, cnt); return ;}
            f(row, col + 1, cnt);
        }
        else {
            mb[row][col] = 1;
            cnt += mb[row][col] - ma[row][col];
            if (col > 1 && !is_even(row, col - 1)) return;
            if (col == n) {rnt = min(rnt, cnt); return ;}
            f(row, col + 1, cnt);
        }
    }
    else if (row == 1) {
        for (mb[row][col] = ma[row][col]; mb[row][col] <= 1; mb[row][col]++) {
            cnt += mb[row][col] - ma[row][col];
            if (col == n) f(row + 1, 1, cnt);
            else f(row, col + 1, cnt);
        }
    }
    else {
        if (is_even(row - 1, col)) {
            if (ma[row][col] == 1) return;
            mb[row][col] = 0;
            if (col == n) f(row + 1, 1, cnt);
            else f(row, col + 1, cnt);
        }
        else {
            mb[row][col] = 1;
            cnt += mb[row][col] - ma[row][col];
            if (col == n) f(row + 1, 1, cnt);
            else f(row, col + 1, cnt);
        }
    }
}

int main()
{
    int c,t,i,j;
    cin >> c;
    for (t = 1; t <= c; t++) {
        rnt = 4444444;
        cin >> n;
        for (i = 1; i <= n; i++) 
            for (j = 1; j <= n; j++)
                cin >> ma[i][j];
        f(1, 1, 0);
        if (rnt == 4444444) printf("Case %d: -1\n", t);
        else printf("Case %d: %d\n", t, rnt);
    }
    return 0;
}
