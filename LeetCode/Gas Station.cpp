#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int len;
		int start, end;
		int gas_left;

		len = gas.size();
		start = end = gas_left = 0;

		for (; start < len; ) {
			if (start == end && gas[start] < cost[start]) {
				++start;
				++end;
				gas_left = 0;
				continue;
			}

			if (gas_left < 0) {
				gas_left -= gas[start] - cost[start];
				++start;
				continue;
			} else {
				gas_left += gas[end] - cost[end];

				if (gas_left >= 0 && (end + 1) % len == start)
					return start;


				end = (end + 1) % len;
			}
		}

		return -1;
    }
};

int main()
{
	Solution sol;
	vector<int> gas, cost;

	gas.push_back(4);
	gas.push_back(2);
	gas.push_back(3);
	gas.push_back(3);

	cost.push_back(2);
	cost.push_back(5);
	cost.push_back(2);
	cost.push_back(2);

	cout << sol.canCompleteCircuit(gas, cost) << endl;
}
