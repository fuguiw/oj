#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAXN 100004

struct _node{
    int x, y;
}node[MAXN];

bool cmp(_node a, _node b) 
{
    long long x1, x2, y1, y2;
    x1 = a.x;
    y1 = a.y;
    x2 = b.x;
    y2 = b.y;
    return x1 * x1 + y1 * y1 < x2 * x2 + y2 * y2;
}

int main()
{
    int n, i, rnt;
    int x[MAXN], y[MAXN];
    while (cin >> n) {
        rnt = 0;
        for (i = 0; i < n; i++) {
            scanf("%d%d", &node[i].x, &node[i].y);
            if (node[i].x) rnt += 2;
            if (node[i].y) rnt += 2;
            rnt += 2;
        }
        printf("%d\n", rnt);

        sort(node, node + n, cmp);
        for (i = 0; i < n; i++) {
            if (node[i].x > 0) printf("1 %d R\n", node[i].x);
            if (node[i].x < 0) printf("1 %d L\n", -node[i].x);
            if (node[i].y > 0) printf("1 %d U\n", node[i].y);
            if (node[i].y < 0) printf("1 %d D\n", -node[i].y);
            printf("2\n");
            if (node[i].x > 0) printf("1 %d L\n", node[i].x);
            if (node[i].x < 0) printf("1 %d R\n", -node[i].x);
            if (node[i].y > 0) printf("1 %d D\n", node[i].y);
            if (node[i].y < 0) printf("1 %d U\n", -node[i].y);
            printf("3\n");
        }
    }
    return 0;
}
