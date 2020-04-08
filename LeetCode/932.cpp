#include <vector>
using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> ans;
        ans.push_back(1);
        while (ans.size() < N) {
            vector<int> tmp;
            for (int i = 0; i < ans.size(); i++) {
                if (ans[i] * 2 - 1 <= N) {
                    tmp.push_back(ans[i] * 2 - 1);
                }
            }
            for (int i = 0; i < ans.size() ; i++) {
                if (ans[i] * 2 <= N) {
                    tmp.push_back(ans[i] * 2);
                }
            }
            ans = tmp;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    sol.beautifulArray(5);
}