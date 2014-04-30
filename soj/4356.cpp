#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1444444444

struct _giant {
    int level;
    int appetite;
};

int main()
{
    int t, n, p, rnt, flag, tmp, pleft, i, j, left, right, mid;
    int num[101];
    struct _giant giant[101][100];
    cin >> t;
    while (t--) {
        rnt = -1;
        cin >> n >> p;
        for (i = 0; i < n; i++) {
            cin >> num[i];
            for (j = 0; j < num[i]; j++) {
                cin >> giant[i][j].level >> giant[i][j].appetite;
            }
        }
        left = 1;
        right = 1000000000;
        while (left <= right) {
            mid = (left + right) / 2;
            flag = 0;
            pleft = p;
            for (i = 0; i < n; i++) {
                tmp = INF;
                for (j = 0; j < num[i]; j++) {
                    if (giant[i][j].level >= mid) {
                        if (giant[i][j].level == mid) flag = 1;
                        tmp = min(tmp, giant[i][j].appetite);
                    }
                }
                if (tmp == INF) {pleft = -1; break;}
                pleft -= tmp;
                if (pleft < 0) break;
            }
            if (pleft < 0) {right = mid - 1;continue;}
            if (flag == 1) rnt = max(rnt, mid);
            left = mid + 1;
        }
        if (rnt == -1) {
            cout << "We need to talk!" << endl;
        } else {
            cout << rnt << endl;
        }
    }
    return 0;
}

