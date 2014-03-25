#include <iostream>
using namespace std;

int main()
{
    int i, j, num, t, n, p;
    cin >> t;
    while (t--) {
        cin >> n >> p;
        num = n * 2 + p;
        for (i = 1; i <= n; i++) {
            for (j = i + 1;j <= n;j++) {
                cout << i << " " << j << endl;
                num--;
                if (num == 0) break;
            }
            if (num == 0) break;
        }
    }
    return 0;
}
