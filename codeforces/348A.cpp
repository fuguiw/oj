#include <iostream>
#include <cmath>
using namespace std;

long long max(long long a, long long b) {
    return a > b ? a : b;
}

int main()
{
    long long rnt, sum;
    int n, temp, i;
    while (cin >> n) {
        rnt = -1;
        sum = 0;
        for (i = 0; i < n; i++) {cin >> temp; sum += temp; rnt = max(rnt, temp);}
        temp = ceil(1.0 * sum / (n - 1));
        rnt = max(rnt, temp);
        cout << rnt << endl;
    }
    return 0;
}
