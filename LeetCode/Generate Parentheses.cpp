#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
	vector<string> parentheses;
	int num;

	void generate(int left, int right, string s) {
		if (left == num && right == num) {
			parentheses.push_back(s);
			return ;
		}

		if (left < num)
			generate(left + 1, right, s + "(");

		if (right < left)
			generate(left, right + 1, s + ")");
	}

public:
    vector<string> generateParenthesis(int n) {
		parentheses.clear();
		num = n;

		generate(0, 0, "");

		return parentheses;
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	vector<string> v;

	v = sol.generateParenthesis(10);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	return 0;
}
