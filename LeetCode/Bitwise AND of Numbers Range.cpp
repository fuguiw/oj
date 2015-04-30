#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ret, tmp;
        ret = tmp = m;
        
        for (int i = 0; i < 31; i++) {
            if (ret == 0 || m == n)
                break;

            ret &= tmp;

            if (n - (1 << i) < m)
                break;
            tmp = m + (1 << i);
        }

        return ret & n;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    cout << sol.rangeBitwiseAnd(2100000000,2100000001) << endl;
    return 0;
}

