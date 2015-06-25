class Solution {
public:
    void push(int value) {
        int min_value = INT_MAX;
        if (!min_stack_.empty())
            min_value = min_stack_.top();
        if (value <= min_value)
            min_stack_.push(value);
        stack_.push(value);
    }

    void pop() {
        int value = stack_.top();
        stack_.pop();
        if (value == min_stack_.top())
            min_stack_.pop();
    }

    int top() {
        return stack_.top();
    }

    int min() {
        return min_stack_.top();
    }

private:
    stack<int> stack_;
    stack<int> min_stack_;
};
