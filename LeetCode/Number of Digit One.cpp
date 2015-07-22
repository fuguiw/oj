#include <iostream>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int len = 0;
        for (int tmp = n; tmp; tmp /= 10)
            len++;

        int num = 0;
        long long weight = 10;
        for (int i = 0; i < len; i++) {
            num += n / weight * (weight / 10);
            int tmp = n / (weight / 10) % 10;

            if(tmp == 1)
                num += n % (weight / 10) + 1;
            if(tmp > 1)
                num += (weight / 10);

            weight *= 10;
        }

        return num;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int n;
    while (cin >> n) {
        cout << sol.countDigitOne(n) << endl;
    }
    return 0;
}
