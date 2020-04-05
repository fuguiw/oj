#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.empty()) {
            return ans;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int> x, vector<int> y) -> bool {
            return x[0] < y[0];
        });

        int begin = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > end) {
                ans.push_back(vector<int>{begin, end});
                begin = intervals[i][0];
                end = intervals[i][1];
                continue;
            }
            end = max(end, intervals[i][1]);
        }
        ans.push_back(vector<int>{begin, end});
        return ans;
    }
};