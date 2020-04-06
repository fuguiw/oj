#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
                continue;
            }
            if (st.empty()) {
                return false;
            }
            char tc = st.top();
            st.pop();
            if (c == ')' && tc != '(') {return false;}
            if (c == ']' && tc != '[') {return false;}
            if (c == '}' && tc != '{') {return false;}
        }
        return st.empty();
    }
};