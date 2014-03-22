#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define MAXN 100000

struct _v {
    int i;
    int d;
};

struct _v v[MAXN];
int n, k;

bool cmp(struct _v a, struct _v b)
{
    return a.d < b.d;
}

int is_exist()
{
    long long pcnt = 1, cnt = 1;
    if (v[0].d != 0 || v[1].d != 1) return 0;
    for (int i = 1; i < n; i++) {
        if (v[i].d - v[i - 1].d > 1) return 0;
        if (v[i].d - v[i - 1].d == 1) {
            if (v[i].d == 2 && cnt > pcnt * k) return 0;
            if (v[i].d > 2 && cnt > pcnt * (k - 1)) return 0;
            pcnt = cnt;
            cnt = 1;
        }
        if (v[i].d - v[i - 1].d == 0)
            cnt++;
    }
    if (v[n - 1].d >= 2 && cnt > pcnt * (k - 1)) return 0;
    if (v[n - 1].d == 1 && cnt > k) return 0;
    return 1;
}

int main()
{
    int i, j, l, cnt;
    while (cin >> n >> k) {
        for (i = 0; i < n; i++) {
            cin >> v[i].d;
            v[i].i = i + 1;
        }
        sort(v, v + n, cmp);
        if (!is_exist()) {
            cout << -1 << endl;
            continue;
        }
        cout << n - 1 << endl;
        for (i = 1, j = 0, l = 1, cnt = 1; i < n; i++) {
            if (v[i].d - v[j].d == 2) {
                j = l;
                l = i;
                cnt = 3;
                cout << v[j].i << " " << v[i].i << endl;
            } else {
                cout << v[j].i << " " << v[i].i << endl;
                cnt++;
                if ((cnt > k) && (v[i + 1].d - v[j].d == 1)) {
                    cnt = 2;
                    j++;
                }
            }
        }
    }
    return 0;
}
