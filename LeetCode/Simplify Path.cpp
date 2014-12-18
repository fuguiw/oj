#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
		stack<string> st;
		istringstream is(path);
		string p;
		string simplePath;
		
		while (getline(is, p, '/')) {
			if (p == "." || p == "")
				continue;

			if (p == "..") {
				if (!st.empty())
					st.pop();
			} else {
				st.push(p);
			}
		}
		
		while (!st.empty()) {
			p = st.top();
			st.pop();
			simplePath = "/" + p + simplePath;
		}

		if (simplePath == "")
			simplePath = "/";

		return simplePath;
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	string path;

	while (cin >> path)
		cout << sol.simplifyPath(path) << endl;

	return 0;
}
