#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> maxProfitBefore(len + 1, 0);
        vector<int> maxProfitAfter(len + 1, 0);

        int minPrice = INT_MAX;
        for (int i = 1; i <= len; i++) {
            minPrice = min(minPrice, prices[i - 1]);
            maxProfitBefore[i] = max(maxProfitBefore[i - 1], prices[i - 1] - minPrice);
        }

        int maxPrice = INT_MIN;
        for (int i = len - 1; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            maxProfitAfter[i] = max(maxProfitAfter[i + 1], maxPrice - prices[i]);
        }

        int rnt = 0;
        for (int i = 0; i <= len; i++)
            rnt = max(rnt, maxProfitBefore[i] + maxProfitAfter[i]);

        return rnt;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> prices{1,3,2,4,2,7,5};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
