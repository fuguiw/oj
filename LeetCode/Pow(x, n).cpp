#include <iostream>
using namespace std;

class Solution {
public:
    double _pow(double x, int n) {
        if (n == 0)
            return 1;

        if (n % 2)
            return pow(x * x, n / 2) * x;
        else
            return pow(x * x, n / 2);
    }

    double pow(double x, int n) {
        if (n > 0)
            return _pow(x, n);
        else
            return 1.0 / _pow(x, -n);
    }
};

int main(int argc, char *argv[])
{
    double d;
    int n;
    Solution sol;
    
    while (cin >> d >> n)
        cout << sol.pow(d, n) << endl;

    return 0;
}
