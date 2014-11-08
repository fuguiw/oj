class Solution {
public:
    int romanToInt(string s) {
		map<char, int> val;
		val['I'] = 1;
		val['V'] = 5;
		val['X'] = 10;
		val['L'] = 50;
		val['C'] = 100;
		val['D'] = 500;
		val['M'] = 1000;
		int len = s.size();
		int pre = 4444;
		int integer = 0;
		int tmp;

		for (int i = 0; i < len; i++) {
			tmp = val[s[i]];
			integer += tmp;
			if (pre < tmp)
				integer -= 2 * pre;
			pre = tmp;
		}
		return integer;
    }
};

