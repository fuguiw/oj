#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int array[1000][100], sarr[1000][100];
int rnt[5000][2];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n, m, k, i, j, cnt, x, y;
    while (cin >> n >> m >> k) {
        cnt = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> array[i][j];
                sarr[i][j] = array[i][j];
            }
            if (k == 0) sort(sarr[i], sarr[i] + m);
            if (k == 1) sort(sarr[i], sarr[i] + m, cmp);
        }
        if (k == 0) {
            for (j = 0; j < m; j++) {
                for (i = 0; i < n; i++) {
                    if (array[i][j] != sarr[i][j]) {
                        for (x = j + 1; x < m; x++) {
                            if (array[i][x] == sarr[i][j]) {
                                rnt[cnt][0] = j + 1;
                                rnt[cnt++][1] = x + 1;
                                swap(array[i][j], array[i][x]);
                                break;
                            }
                        }
                        for (y = i + 1; y < n; y++) 
                            if (array[y][x] < array[y][j]) 
                                swap(array[y][x], array[y][j]);
                    }
                }
            }
        }
        if (k == 1) {
            for (j = 0; j < m; j++) {
                for (i = 0; i < n; i++) {
                    if (array[i][j] != sarr[i][j]) {
                        for (x = j + 1; x < m; x++) {
                            if (array[i][x] == sarr[i][j]) {
                                rnt[cnt][0] = x + 1;
                                rnt[cnt++][1] = j + 1;
                                swap(array[i][j], array[i][x]);
                                break;
                            }
                        }
                        for (y = i + 1; y < n; y++) 
                            if (array[y][x] > array[y][j]) 
                                swap(array[y][x], array[y][j]);
                    }
                }
            }
        }
        cout << cnt << endl;
        for (i = 0; i < cnt; i++) 
            cout << rnt[i][0] << " " << rnt[i][1] << endl;
    }
    return 0;
}
