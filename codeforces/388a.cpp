#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int s[100], i, j, n, rnt;
    while (cin >> n) {
        for (i = 0; i < n; i++) cin >> s[i];
        sort(s, s + n);
        for (rnt = 1; rnt <= n; rnt++) {
            for (j = 0; j < n; j++) {
                if (s[j] - j / rnt < 0) break;
            }
            if (j == n) break;
        }
        cout << rnt << endl;
    }
    return 0;
}

