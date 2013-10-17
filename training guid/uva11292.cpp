#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 20000
int k[MAXN],d[MAXN];

int main()
{
    int n,m,i,j,rnt;
    while (cin >> n >> m && n) {
        rnt = 0;
        for (i = 0; i < n; i++) scanf("%d", &d[i]);
        for (i = 0; i < m; i++) scanf("%d", &k[i]);
        sort(d, d + n);
        sort(k, k + m);

        for (i = j = 0; i < n && j < m; j++) {
            if (k[j] >= d[i]) {
                rnt += k[j];
                i++;
                continue;
            }
        }
        if (i < n) printf("Loowater is doomed!\n");
        else printf("%d\n", rnt);
    }
    return 0;
}
