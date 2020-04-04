#include <map>
using namespace std;

class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        map<int, int> m;
        for (int i = 1; i <= n; i++) {
            m[getSum(i)]++;
        }

        int mm = -1;
        for (auto itr = m.begin(); itr != m.end(); itr++) {
            mm = max(mm, itr->second);
        }
        int ans = 0;
        for (auto itr = m.begin(); itr != m.end(); itr++) {
            if (itr->second == mm) {
                ans++;
            }
        }
        return ans;
    }
};
