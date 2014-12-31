#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int rnt = 0;

        for (long long t = 5; t <= n; t *= 5)
            rnt += n / t;

        return rnt;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int n;

    while (cin >> n) {
        cout << sol.trailingZeroes(n) << endl;
    }

    return 0;
}

