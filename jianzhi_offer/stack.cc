class Solution
{
public:
    void push(int node) {
        stack2.push(node);
    }

    int pop() {
        if (stack1.empty()) {
            while (!stack2.empty()) {
                int node = stack2.top();
                stack2.pop();
                stack1.push(node);
            }
        }
        
        int node = stack1.top();
        stack1.pop();

        return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
