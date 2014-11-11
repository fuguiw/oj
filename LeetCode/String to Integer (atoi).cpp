#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
private:
	long long _atoi(const char *str) {
		int len = strlen(str);
		long long integer = 0;
		for (int i = 0; i < len; i++) {
			if (!isdigit(str[i]))
				return integer;
			integer = integer * 10 + str[i] - '0';
			if (integer - 1 > INT_MAX)
				return integer;
		}
		return integer;
	}
	long long min(long long a, long long b) {
		return a < b ? a : b;
	}
	long long max(long long a, long long b) {
		return a > b ? a : b;
	}
public:
    int atoi(const char *str) {
		int len = strlen(str);
		int i;
		long long integer;
		
		if (!str)
			return 0;
		for (i = 0; i < len; i++)
			if (!isspace(str[i]))
				break;
		if (str[i] == '+') {
			return min(INT_MAX, _atoi(&str[i + 1]));
		}
		if (str[i] == '-')
			return max(INT_MIN, -_atoi(&str[i + 1]));
		return min(INT_MAX, _atoi(&str[i]));
    }
};

int main()
{
	Solution sol;
	char str[100];
	while (cin >> str)
		cout << sol.atoi(str) << endl;
	return 0;
}

