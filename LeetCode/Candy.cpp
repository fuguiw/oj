#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int cnt[ratings.size()];

        for (int i = 0; i < ratings.size(); i++)
            cnt[i] = 1;

        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                cnt[i] = max(cnt[i - 1] + 1, cnt[i]);
            }
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                cnt[i] = max(cnt[i + 1] + 1, cnt[i]);
            }
        }

        int ret = 0;
        for (int i = 0; i < ratings.size(); i++)
            ret += cnt[i];

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v;
    /* 4,2,3,4,1 */
    v.push_back(4);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    /* v.push_back(4); */

    cout << sol.candy(v) << endl;

    return 0;
}
