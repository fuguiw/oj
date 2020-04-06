#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> x, vector<int> y) -> bool {
            return x[0] < y[0];
        });

        auto cmp = [](pair<int, int> x, pair<int, int> y) { return x.second > y.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (vector<int> interval : intervals) {
            if (pq.empty() || pq.top().second > interval[0]) {
                pq.push(pair<int,int>{interval[0], interval[1]});
                continue;
            }
            auto p = pq.top();
            pq.pop();
            p.second = interval[1];
            pq.push(p);
        }

        return pq.size();
    }
};