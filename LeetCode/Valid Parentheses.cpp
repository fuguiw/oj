class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		int len = s.size();

		for (int i = 0; i < len; i++) {
			if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
				st.push(s[i]);
				continue;
			}
			if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
				if (st.empty()) 
					return false;
				char tmp = st.top();
				if (s[i] == '}' && tmp == '{') {
					st.pop();
					continue;
				}
				if (s[i] == ']' && tmp == '[') {
					st.pop();
					continue;
				}
				if (s[i] == ')' && tmp == '(') {
					st.pop();
					continue;
				}
				return false;
			}
		}
		if (!st.empty()) 
			return false;
		else 
			return true;
	}
};

