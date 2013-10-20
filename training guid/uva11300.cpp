#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 1000000 + 4
long long a[MAXN],c[MAXN];


int main()
{
    long long i,n,m,tot,ans,x1;
    while (cin >> n) {
        tot = ans = 0;
        for (i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            tot += a[i];
        }
        m = tot / n;
        c[0] = 0;
        for (i = 1; i <= n; i++) {
            c[i] = a[i] - m + c[i - 1];
        }
        sort(c + 1, c + n + 1);
        x1 = c[(n + 1) / 2];
        for (i = 1; i <= n; i++) {
            ans += fabs(x1 - c[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
