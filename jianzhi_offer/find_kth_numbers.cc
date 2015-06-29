#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> v;
        if (k > input.size())
            return v;
        priority_queue<int, vector<int>, std::greater<int>> q;
        for (int num : input)
            q.push(num);
        while (k--) {
            int num = q.top();
            q.pop();
            v.push_back(num);
        }
        return v;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v{4,5,1,6,2,7,3,8};
    v = sol.GetLeastNumbers_Solution(v, 4);
    for (auto i : v)
        cout << i << endl;
    return 0;
}
