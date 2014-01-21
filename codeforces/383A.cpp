#include <iostream>
using namespace std;

int main()
{
    long long n, i, dir, rnt, cnt;
    while (cin >> n) {
        for (i = rnt = cnt = 0; i < n; i++) {
            cin >> dir;
            if (dir) cnt++;
            else rnt += cnt;
        }
        cout << rnt << endl;
    }
    return 0;
}
