#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct _s
{
    int b;
    int j;
}s[1000];

bool cmp(_s a, _s b)
{
    if (a.j == b.j) return a.b < b.b;
    return a.j > b.j;
}

int main()
{
    int i,k,n,cnt = 0,m,rnt;
    int sum[1004];
    while (cin >> n && n) {
        rnt = 0;
        cnt++;
        for (i = 0; i < n; i++) {
            cin >> s[i].b >> s[i].j;
            rnt += s[i].b;
        }
        sort(s, s + n, cmp);
        sum[n] = 0;
        for (i = n - 1; i >= 0; i--) {
            sum[i] = s[i].b + sum[i + 1];
        }
        for (i = m = 0; i < n; i++) {
            if (m < s[i].j - sum[i + 1]) 
                m = s[i].j - sum[i + 1];
        }
        printf("Case %d: %d\n", cnt, rnt + m);
    }
    return 0;
}
