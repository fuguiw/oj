#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    bool VerifySquenceOfBST(vector<int>& sequence, 
                       int min_value, int max_value, 
                       bool min_flag, bool max_flag,
                       int begin, int end) {
        if (begin == end)
            return true;

        int mid_value = sequence[end - 1];
        if (min_flag && mid_value < min_value) return false;
        if (max_flag && mid_value > max_value) return false;
        if (begin + 1 == end)
            return true;

        int i;
        for (i = begin; i < end - 1; i++) {
            if (min_flag && sequence[i] < min_value) return false;
            if (max_flag && sequence[i] > max_value) return false;
            if (sequence[i] > mid_value)
                break;
        }

        return VerifySquenceOfBST(sequence, min_value, mid_value, min_flag, true, begin, i)
                && VerifySquenceOfBST(sequence, mid_value, max_value, true, max_flag, i, end - 1);

    }
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty())
            return false;
        return VerifySquenceOfBST(sequence, 0, 0, false, false, 0, sequence.size());
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v{1,3,2,5,6,7,4};
    cout << sol.VerifySquenceOfBST(v) << endl;
    return 0;
}
