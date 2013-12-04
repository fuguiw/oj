#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 204

struct _node {
    int num;
    int idx;
    int heap;
}node[MAXN];

bool cmp(struct _node a, struct _node b)
{
    return a.num > b.num;
}

int main()
{
    int n, r1, r2, i, h, cnt1, cnt2;
    int tmp;
    int t[MAXN], vis1[MAXN], vis2[MAXN];
    while (cin >> n) {
        r1 = r2 = 0;
        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, sizeof(vis2));
        for (i = 0; i < 2 * n; i++) {
            cin >> tmp;
            node[i].num = tmp;
            node[i].idx = i;
            node[i].heap = 0;
        }

        sort(node, node + 2 * n, cmp);

        for (i = 0; i < 2 * n; i++) {
            if (vis1[node[i].num] && vis2[node[i].num]) continue;
            if (!vis1[node[i].num] && !vis2[node[i].num]) {
                if (r1 == r2) {
                    r1++;
                    vis1[node[i].num] = 1;
                    node[i].heap = 1;
                }
                else {
                    r2++;
                    vis2[node[i].num] = 1;
                    node[i].heap = 2;
                }
            }
            else if (vis1[node[i].num]) {
                r2++;
                vis2[node[i].num] = 1;
                node[i].heap = 2;
            }
            else {
                r1++;
                vis1[node[i].num] = 1;
                node[i].heap = 1;
            }
            t[node[i].idx] = i;
        }

        cnt1 = r1;
        cnt2 = r2;

        for (i = 0; i < 2 * n; i++) {
            if (node[i].heap) continue;
            if (cnt1 == cnt2) {node[i].heap = 1; cnt1++;}
            else {node[i].heap = 2; cnt2++;}
            t[node[i].idx] = i;
        }

        cout << r1 * r2 << endl;
        for (i = 0; i < 2 * n; i++)
            cout << node[t[i]].heap << " ";
        cout << endl;
    }
    return 0;
}
