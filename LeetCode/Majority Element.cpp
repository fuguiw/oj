class Solution {
public:
    int majorityElement(vector<int> &num) {
		int n = num.size();
		int cnt = 1;
		int ret = num[0];

		for (int i = 1; i < n; i++) {
			if (num[i] == ret) {
				++cnt;
			} else {
				--cnt;
				if (!cnt) {
					cnt = 1;
					ret = num[i];
				}
			}
		}

		return ret;
    }
};
