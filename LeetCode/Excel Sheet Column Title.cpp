#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
		string s;

		do {
			s.insert(0, 1, (n - 1) % 26 + 'A');
		} while (n = (n - 1) / 26);

		return s;
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	int n;
	
	while (cin >> n)
		cout << sol.convertToTitle(n) << endl;

	return 0;
}
