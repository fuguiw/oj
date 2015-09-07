#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if (len == 0)
            return 0;

        sort(citations.begin(), citations.end());
        for (int i = min(len, citations.back()); i > 0; --i) {
            int idx = lower_bound(citations.begin(), citations.end(), i) - citations.begin();
            int cnt = len - idx;
            if (i <= cnt)
                return i;
        }
        return 0;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v = {0,1,3,5,6};
    cout << sol.hIndex(v) << endl;
    return 0;
}

