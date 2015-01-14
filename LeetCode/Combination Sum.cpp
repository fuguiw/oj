#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int> > rnt;
    vector<int> v;

    void f(vector<int> &candidates, int i, int sum, int target) {
        int len = candidates.size();

        for (int j = i; j < len; j++) {
            if (candidates[j] + sum == target) {
                v.push_back(candidates[j]);
                rnt.push_back(v);
                v.pop_back();
                return ;
            } else if (candidates[j] + sum > target) {
                return ;
            } else {
                v.push_back(candidates[j]);
                f(candidates, j, sum + candidates[j], target);
                /* f(candidates, j + 1, sum + candidates[j], target); */
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        f(candidates, 0, 0, target);
        return rnt;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v;
    vector<vector<int> > vv;

    v.push_back(3);
    v.push_back(6);
    v.push_back(2);
    v.push_back(7);

    vv = sol.combinationSum(v, 7);

    for (int i = 0; i < vv.size(); i++)
        for (int j = 0; j < vv[i].size(); j++)
            cout << vv[i][j] << endl;

    return 0;
}
