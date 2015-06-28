#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> v;

        int i, j;
        for (i = 0, j = array.size() - 1; i < j; ) {
            int tmp = array[i] + array[j];
            if (tmp == sum) {
                if (v.empty()) {
                    v.push_back(array[i]);
                    v.push_back(array[j]);
                } else {
                    if (1.0 * array[i] * array[j] < 1.0 * v[0] * v[1]) {
                        v[0] = i;
                        v[1] = j;
                    }
                }
                ++i;
                --j;
            } else if (tmp > sum) {
                --j;
            } else {
                ++i;
            }
        }

        return v;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    v = sol.FindNumbersWithSum(v, 21);
    cout << v[0] << " " << v[1] << endl;
    return 0;
}
