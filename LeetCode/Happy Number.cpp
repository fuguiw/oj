#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        s.insert(n);

        while (1) {
            n = convert(n);

            if (n == 1)
                return true;

            if (s.find(n) == s.end())
                s.insert(n);
            else 
                return false;
        }
    }

private:
    int convert(int n) {
        int ret = 0;

        while (n) {
            ret += pow(n % 10, 2);
            n /= 10;
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    int n;
    while (cin >> n)
        cout << sol.isHappy(n) << endl;

    return 0;
}

