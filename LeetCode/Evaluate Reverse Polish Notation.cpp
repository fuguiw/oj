#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st; 

        for (auto &token : tokens) {
            if (token == "+") {
                string n1 = st.top();
                st.pop();
                string n2 = st.top();
                st.pop();
                st.push(to_string(stoi(n1) + stoi(n2)));
            } else if (token == "-") {
                string n1 = st.top();
                st.pop();
                string n2 = st.top();
                st.pop();
                st.push(to_string(stoi(n2) - stoi(n1)));
            } else if (token == "*") {
                string n1 = st.top();
                st.pop();
                string n2 = st.top();
                st.pop();
                st.push(to_string(stoi(n1) * stoi(n2)));
            } else if (token == "/") {
                string n1 = st.top();
                st.pop();
                string n2 = st.top();
                st.pop();
                st.push(to_string(stoi(n2) / stoi(n1)));
            } else {
                st.push(token);
            }
        }

        return stoi(st.top());
    }
};

                st.pop();
                string n2 = st.top();
                st.pop();
                st.push(to_string(stoi(n1) * stoi(n2)));
            } else if (token == "/") {
                string n1 = st.top();
                st.pop();
                string n2 = st.top();
                st.pop();
                st.push(to_string(stoi(n2) / stoi(n1)));
            } else {
                st.push(token);
            }
        }

        return stoi(st.top());
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<string> v{"4", "13", "5", "/", "+"};
    
    cout << sol.evalRPN(v) << endl;

    return 0;
}
