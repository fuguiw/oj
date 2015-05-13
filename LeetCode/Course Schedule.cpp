#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> v(numCourses, 0);
        vector<vector<int>> vv(numCourses);

        for (auto it = prerequisites.cbegin(); it != prerequisites.cend(); it++) {
            v[it->second]++;
        }

        for (auto it = prerequisites.cbegin(); it != prerequisites.cend(); it++) {
            vv[it->first].push_back(it->second);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (v[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int n = q.front();
            q.pop();

            for (auto it : vv[n]) {
                v[it]--;
                if (v[it] == 0)
                    q.push(it);
            }
        }

        for (auto it : v)
            if (it > 0)
                return false;

        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    vector<pair<int, int>> v;

    v.push_back(make_pair(1, 0));
    v.push_back(make_pair(0, 1));

    cout << sol.canFinish(2, v) << endl;

    return 0;
}

