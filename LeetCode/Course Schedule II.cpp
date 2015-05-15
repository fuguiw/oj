#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> pre_cnt(numCourses, 0);
        for (auto &p : prerequisites) {
            adj[p.second].push_back(p.first);
            pre_cnt[p.first]++;
        }

        vector<int> order;
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (pre_cnt[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);
            for (auto c : adj[course]) {
                if (--pre_cnt[c] == 0)
                    q.push(c);
            }
        }

        if (order.size() != numCourses)
            return vector<int>();
        return order;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<pair<int, int>> vv;

    vv.push_back(make_pair(1, 0));
    vv.push_back(make_pair(2, 0));
    vv.push_back(make_pair(3, 1));
    vv.push_back(make_pair(3, 2));

    vector<int> v = sol.findOrder(4, vv);

    for (auto i : v)
        cout << i << endl;

    return 0;
}
