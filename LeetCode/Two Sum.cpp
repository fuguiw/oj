class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> index;
		map<int, int> m;
		int i, j, tmp;
		int len = numbers.size();

		for (i = 0; i < len; i++)
			m[numbers[i]]++;

		for (i = 0; i < len; i++) {
			tmp = target - numbers[i];
			if (m[tmp]) {
				if (tmp == numbers[i] && m[tmp] == 1)
					continue;

				for (j = i + 1; j < len; j++)
					if (numbers[j] == tmp)
						break;
				index.push_back(i + 1);
				index.push_back(j + 1);
				break;
			}
		}

		return index;
    }
};
