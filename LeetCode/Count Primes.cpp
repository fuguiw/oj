#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        bool *primes = new bool[n];
        memset(primes, 1, n);
        double c = sqrt(n);

        for (int i = 2; i <= c; i++) {
            if (primes[i] == false)
                continue;
            for (int j = i * i; j < n; j += i)
                    primes[j] = false;
        }

        int count = 0;
        for (int i = 2; i < n; i++)
            count += primes[i];

        delete [] primes;
        return count;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int n;

    while (cin >> n)
        cout << sol.countPrimes(n) << endl;

    return 0;
}
