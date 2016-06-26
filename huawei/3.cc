#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    int i, j;
    int n;
    cin >> n;

    vector<int> t(n);
    for (i = 0; i < n; i++)
        cin >> t[i];

    vector<int> cnt(n, 1);
    for (i = 0; i < n; i++) {
        for (j = i - 1; j >= 0; j--) {
            if (t[i] > t[j])
                cnt[i] = max(cnt[i], cnt[j] + 1);
        }
    }

    vector<int> inverse_cnt(n, 1);
    for (i = n - 1; i >= 0; i--) {
        for (j = i + 1; j < n; j++) {
            if (t[i] > t[j])
                inverse_cnt[i] = max(inverse_cnt[i], inverse_cnt[j] + 1);
        }
    }

    int rnt = 0;
    for (i = 0; i < n; i++)
        rnt = max(rnt, cnt[i] + inverse_cnt[i] - 1);

    cout << n - rnt << endl;

    return 0;
}
