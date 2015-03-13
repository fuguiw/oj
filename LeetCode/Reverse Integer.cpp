#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
private:
    int doReverse(int x) {
        int ret = 0;
        while (x) {

            if (ret) 
                if (INT_MAX / ret < 10)
                    return 0;

            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return ret;
    }
public:
    int reverse(int x) {
        if (x < 0) return -doReverse(-x);
        else return doReverse(x);
    }
};

int main()
{
    Solution sol;
    int n;

    cout << INT_MAX << endl;
    while (cin >> n)
        cout << sol.reverse(n) << endl;

    return 0;
}
