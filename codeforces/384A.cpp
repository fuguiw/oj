#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, i, j, rnt;
    while (cin >> n) {
        if (n % 2) printf("%d\n", (n / 2) * (n / 2) + (n / 2 + 1) * (n / 2 + 1));
        if (!(n % 2)) printf("%d\n", (n / 2) * n);
        for (i = 0; i < n; i++) {
            if (!(i % 2)) {
                for (j = 0; j < n; j++) {
                    if (j % 2) cout << '.';
                    else {cout << 'C'; rnt++;}
                }
                cout << endl;
            }
            if (i % 2) {
                for (j = 0; j < n; j++) {
                    if (j % 2) {cout << 'C'; rnt++;}
                    else cout << '.';
                }
                cout << endl;
            }
        }
    }
    return 0;
}
