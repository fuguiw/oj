#include <iostream>
using namespace std;
#define MAXN 100000 + 4
int s[MAXN], m[MAXN];

int main()
{
    int t,rnt,i,n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> s[i];
        m[n - 1] = s[n - 1];
        for (i = n - 2; i >= 0; i--)
            m[i] = min(m[i + 1], s[i]);
        rnt = -4444444;
        for (i = n - 2; i >= 0; i--)
            rnt = max(rnt, s[i] - m[i + 1]);
        cout << rnt << endl;
    }
    return 0;
}
