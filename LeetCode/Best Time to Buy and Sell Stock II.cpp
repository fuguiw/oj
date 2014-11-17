class Solution {
public:
    int maxProfit(vector<int> &prices) {
		int len = prices.size();
		int profit;
		int tmp;

		if (!len)
			return 0;

		profit = 0;
		tmp = prices[0];
		for (int i = 1; i < len; i++) {
			if (prices[i] > tmp) {
				profit += prices[i] - tmp;
			}
			tmp = prices[i];
		}

		return profit;
    }
};

