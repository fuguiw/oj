#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int n = height.size();
        
        stack<int> s;
        int ret = 0;
        for (int i = 0; i < n; ) {
            if (s.empty() || height[i] >= height[s.top()]) {
                s.push(i++);
            } else {
                int h = height[s.top()];
                s.pop();
                int j = (s.empty() ? -1 : s.top());
                ret = max(ret, h * (i - j - 1));
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v;
    cout << sol.largestRectangleArea(v) << endl;
    return 0;
}
