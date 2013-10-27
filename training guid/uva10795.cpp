#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 77

long long f(int *p, int i, int e) 
{
    if (i == -1) return 0;
    if (p[i] == e) return f(p, i - 1, e);
    return f(p, i - 1, 6 - p[i] - e) + (1LL << i);
}

int main()
{
    int start[MAXN],finish[MAXN];
    int c = 0,i,n,other;
    long long rnt;
    while (cin >> n && n) {
        rnt = 0;
        for (i = 0; i < n; i++) cin >> start[i];
        for (i = 0; i < n; i++) cin >> finish[i];
        for (i = n - 1; i >= 0; i--) {
            if (start[i] != finish[i]) {
                other = 6 - start[i] - finish[i];
                rnt = f(start, i - 1, other) + f(finish, i - 1, other) + 1;
                break;
            }
        }
        printf ("Case %d: %lld\n", ++c, rnt);
    }
    return 0;
}
