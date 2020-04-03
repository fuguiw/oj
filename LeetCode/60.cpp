#include <string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string str;
        for (int i = 1; i <= n; i++) {
            str += to_string(i);
        }

        while (k > 1) {
            next_permutation(str.begin(), str.end());
            k--;
        }

        return str;
    }
};
