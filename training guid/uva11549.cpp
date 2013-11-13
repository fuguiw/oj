#include <iostream>
#include <cmath>
using namespace std;
int n, k;

int lc(long long num)
{
    int cnt = 0;
    while(num) {
        cnt++;
        num /= 10;
    }
    return cnt;
}

int next(int num)
{
    long long tmp;
    int cnt;
    tmp = (long long)num * num;
    cnt = lc(tmp);
    if(cnt > n) tmp /= pow(10, cnt - n);
    return (int)tmp;
}

int main()
{
    int t, rnt, d1, d2;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        d1 = d2 = rnt = k;
        do {
            d1 = next(d1);
            d2 = next(d2); rnt = max(rnt, d2);
            d2 = next(d2); rnt = max(rnt, d2);
        }while(d1 != d2);
        cout << rnt << endl;
    }
}
