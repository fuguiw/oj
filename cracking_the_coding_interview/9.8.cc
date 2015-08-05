#include <iostream>
#include <vector>
using namespace std;

class Coins {
public:
    static const vector<int> coins;
    static const int kMod = 1000000007;

    int countWays(int n) {
        vector<int> v(n + 1, 0);
        for (int i = 0; i < 4; ++i) {
            v[coins[i]] += 1;
            for (int j = coins[i] + 1; j <= n; ++j) {
                v[j] = (v[j] + v[j - coins[i]]) % kMod;
            }
        }
        return v[n];
    }
};

const vector<int> Coins::coins{1, 5, 10, 25};

int main(int argc, char *argv[])
{
    Coins coin;
    int n;
    while (cin >> n)
        cout << coin.countWays(n) << endl;
    return 0;
}
