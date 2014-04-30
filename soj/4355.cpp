#include <iostream>
using namespace std;

int n;

long long count(int num)
{
    long long cnt;
    long long w;
    long long low = 0, cur = 0, high = 0;

    cnt = 0;
    for (w = 1; n / w; w *= 10) {
        low = n - (n / w) * w;
        cur = n / w % 10;
        high = n / w / 10;
        if (cur < num) cnt += high * w;
        if (cur == num) cnt += high * w + low + 1;
        if (cur > num) cnt += (high + 1) * w;
        if (num == 0) cnt -= w;
    }
    return cnt;
}

int main()
{
    while (cin >> n) {
        for (int i = 0; i <= 9; i++)
            cout << count(i) << endl;
    }
    return 0;
}
