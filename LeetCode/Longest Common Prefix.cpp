class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
		int num = strs.size();
		int rnt;
		int i;
		string cp;
		char tmp;
		if (!num) 
			return cp;
		for (rnt = 0; ; rnt++) {
			for (i = 0; i < num; i++) {
				if (strs[i].size() <= rnt)
					return cp;
				if (i == 0) {
					tmp = strs[i][rnt];
				} else {
					if (strs[i][rnt] != tmp)
						return cp;
				}
			}
			cp.push_back(strs[0][rnt]);
		}
    }
};

