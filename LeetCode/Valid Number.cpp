#include <iostream>
#include <cctype>
using namespace std;

class Solution {
private:
	bool isNum(const char *s, int len) {
		if (len <= 0)
			return false;
		for (int i = 0; i < len; i++) {
			if (!isdigit(s[i])) return false;
		}
		return true;
	}

	bool isSigned(const char *s, int len) {
		if (len <= 0)
			return false;
		if (s[0] == '-' || s[0] == '+') 
			return isNum(s + 1, len - 1);
		return isNum(s, len);
	}

	bool isDecimal(const char *s, int len) {
		int i;

		if (len <= 0)
			return false;
		if (s[0] == '+' || s[0] == '-') {
			s++;
			len--;
		}

		for (i = 0; i < len; i++)
			if (s[i] == '.')
				break;
		if (i == 0) return isNum(s + 1, len - 1);
		if (i == len - 1) return isNum(s, len - 1);
		return (isNum(s, i) && isNum(s + i + 1, len - i - 1));
	}

	bool isFloat(const char *s, int len) {
		int i;
		for (i = 0; i < len; i++)
			if (tolower(s[i]) == 'e')
				break;
		if (isDecimal(s, i) && isSigned(s + i + 1, len - i - 1))
			return true;
		if (isSigned(s, i) && isSigned(s + i + 1, len - i - 1))
			return true;
		return false;
	}

public:
    bool isNumber(const char *s) {
		int begin;
		int end;
		int len = strlen(s);

		for (begin = 0; begin < len; begin++)
			if (!isblank(s[begin])) break;
		for (end = len - 1; end > begin; end--)
			if (!isblank(s[end])) break;
		len = end - begin + 1;

		if (isFloat(s + begin, len)) return true;
		if (isDecimal(s + begin, len)) return true;
		if (isSigned(s + begin, len)) return true;
	
		return false;
    }
};

int main()
{
	char s[100];
	Solution sol;
	while (cin >> s) 
		cout << sol.isNumber(s) << endl;
	return 0;
}
