#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        vector<vector<int>> vv;

        int begin, end, curr_sum;
        for (begin = end = 1, curr_sum = 0; begin < sum; ) {
            if (curr_sum > sum) {
                curr_sum -= begin;
                ++begin;
            } else if (curr_sum < sum) {
                curr_sum += end;
                ++end;
            } else {
                vector<int> v;
                for (int i = begin; i < end; i++)
                    v.push_back(i);
                vv.push_back(v);
                curr_sum += end;
                ++end;
            }
        }

        return vv;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<int>> vv = sol.FindContinuousSequence(0);
    for (auto& v : vv) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
