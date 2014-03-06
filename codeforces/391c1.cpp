#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAXN 15

int p[MAXN], e[MAXN];
int n, k;

int count(int enu)
{
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if ((1 << i) & enu) ret++;
    }
    return ret;
}

int f(int enu)
{
    int score;
    int effort = 0;
    int rate = 1;
    score = count(enu);
    for (int i = 0; i < n; i++) {
        if ((1 << i) & enu) {
            effort += e[i];
            if (p[i] > score) { rate++;}
        }
        else {
            if (p[i] + 1 >= score) rate++;
        }
    }
    if (rate <= k) return effort;
    return -1;
}

int main()
{
    int enu;
    int rnt, ret, i;
    while (cin >> n >> k) {
        enu = 1 << n;
        for (i = 0; i < n; i++) cin >> p[i] >> e[i];
        rnt = -1;
        for (i = 0; i < enu; i++) {
            ret = f(i);
            if (ret == -1) continue;
            if (rnt == -1) rnt = ret;
            else rnt = min(rnt, ret);
        }
        cout << rnt << endl;
    }
    return 0;
}
