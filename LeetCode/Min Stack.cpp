#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class MinStack {
private:
	stack<int> st;
	stack<int> minVal;
public:
    void push(int x) {
		if (st.empty() || x <= minVal.top()) {
			minVal.push(x);
		} 
		st.push(x);
    }

    void pop() {
		if (st.top() == minVal.top())
			minVal.pop();
		st.pop();
    }

    int top() {
		return st.top();
    }

    int getMin() {
		return minVal.top();
    }
};

int main()
{
	MinStack stack;
	stack.push(-1);
	stack.push(4);
	stack.push(7);

	cout << stack.top() << endl;
	cout << stack.getMin() << endl;
	stack.pop();
	cout << stack.top() << endl;
	cout << stack.getMin() << endl;
	stack.pop();
	cout << stack.top() << endl;
	cout << stack.getMin() << endl;
	stack.pop();

	return 0;
}
