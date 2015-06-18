#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (k > (len >> 1)) {
            int rnt = 0;
            for (int i = 1; i < len; i++) 
                    rnt += max(0, prices[i] - prices[i - 1]);

            return rnt;
        }

        vector<int> release(k + 1, 0);
        vector<int> hold(k + 1, INT_MIN);
        for (int price : prices) {
            for (int j = k; j > 0; j--) {
                release[j] = max(release[j], hold[j] + price);
                hold[j] = max(hold[j], release[j - 1] - price);
            }
        }

        return release[k];
    }
};





















int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> prices{1,2,4,2,5,7,2,4,9,0};
    /* vector<int> prices{7,4,1,2}; */
    cout << sol.maxProfit(29, prices) << endl;
    return 0;
}

