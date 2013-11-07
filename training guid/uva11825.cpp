#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 16
#define ALL ((1 << n) - 1)
int p[MAXN], cover[(1 << MAXN)], f[(1 << MAXN)];

int main()
{
    int kase = 1,i,n,m,x,s,s0;
    while(cin >> n && n) {
        for (i = 0; i < n; i++) {
            p[i] = 1 << i;
            cin >> m;
            while (m--) {
                cin >> x;
                p[i] |= (1 << x);
            }
        }

        for (s = 0; s < (1 << n); s++) {
            cover[s] = 0;
            for (i = 0; i < n; i++)
                if (s & (1 << i))
                    cover[s] |= p[i];
        }

        for (s = 0; s < (1 << n); s++) {
            f[s] = 0;
            for (s0 = s; s0; s0 = (s0 - 1) & s)
                if (cover[s0] == ALL)
                    f[s] = max(f[s], f[s ^ s0] + 1);
        }

        printf("Case %d: %d\n", kase++, f[ALL]);
    }
    return 0;
}
