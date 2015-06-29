#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        vector<int> ugly;
        ugly.push_back(0);
        ugly.push_back(1);

        vector<int> v{2,3,5};
        for (int i = 2; i <= index; i++) {
            int pre_ugly = ugly[i - 1];
            int next_ugly = INT_MAX;
            for (int j = 1; j < i; j++) {
                for (int k = 0; k < 3; k++) {
                    if (ugly[j] * v[k] > pre_ugly) {
                        next_ugly = min(next_ugly, ugly[j] * v[k]);
                        break;
                    }
                }
            }
            ugly.push_back(next_ugly);
        }

        return ugly[index];
    }
};

int main(int argc, char *argv[])
{
    int n;
    Solution sol;
    while (cin >> n)
        cout << sol.GetUglyNumber_Solution(n) << endl;
    return 0;
}
