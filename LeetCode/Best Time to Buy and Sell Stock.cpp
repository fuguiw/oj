#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
		int len = prices.size();
		int profit = 0;
		int minPrice;

		if (!len)
			return 0;

		minPrice = prices[0];
		for (int i = 1; i < len; i++) {
			minPrice = min(minPrice, prices[i]);
			profit = max(profit, prices[i] - minPrice);
		}

		return profit;
    }
};

int main()
{
	vector<int> prices;
	prices.push_back(7);
	prices.push_back(4);
	prices.push_back(1);
	Solution sol;
	cout << sol.maxProfit(prices) << endl;
	return 0;
}

