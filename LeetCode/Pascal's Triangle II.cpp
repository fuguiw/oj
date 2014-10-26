#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
	int get_c(long long n, long long m) 
	{
		long long ret = 1;
		long long i, j;

		for (i = n, j = 2; n - i < m; i--) {
			ret *= i;
			if (!(ret % j) && j <= m)
				ret /= j++;
		}

		return ret;
	}

    vector<int> getRow(int rowIndex)
	{
		vector<int> ret;

		for (int i = 0; i <= rowIndex; i++)
			ret.push_back(get_c(rowIndex, min(i, rowIndex - i)));

		return ret;
    }
};

int main()
{
	Solution sol;
	vector<int> v;
	int n;
	
	while(cin >> n) {
		v = sol.getRow(n);
		vector<int>::iterator it;
		for (it = v.begin(); it < v.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
	return 0;
}
