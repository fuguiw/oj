#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100000
int r[MAXN], c[MAXN];

int main()
{
    int n, m, x, y, z, p, i, tmp, tx, ty, tz, tn, tm;
    while (cin >> n >> m >> x >> y >> z >> p) {
        for (i = 0; i < p; i++) 
            cin >> r[i] >> c[i];
        x %= 4; y %= 2; z %= 4;
        cout << endl;
        for (i = 0; i < p; i++) {
            tn = n; tm = m;
            tx = x; ty = y; tz = z;
            while (tx--) {tmp = c[i]; c[i] = tn + 1 - r[i]; r[i] = tmp; swap(tn, tm);}
            while (ty--) {c[i] = tm + 1 - c[i];}
            while (tz--) {tmp = r[i]; r[i] = tm + 1 - c[i]; c[i] = tmp; swap(tn, tm);}
            cout << r[i] << " " << c[i] << endl;
        }
    }
    return 0;
}
