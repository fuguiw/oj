#include <iostream>
using namespace std;

int main()
{
    int n, i, a, b, c, rp, rnt;
    while (cin >> n) {
        for (i = 0; i < n; i++) {
            if (i == 0) {cin >> a; rnt = 1; continue;}
            if (i == 1) {cin >> b; rnt = rp = 2; continue;}
            cin >> c;
            if (a + b == c) {rp++; rnt = max(rp, rnt);}
            else rp = 2;
            a = b; b = c;
        }
        cout << rnt << endl;
    }
    return 0;
}
