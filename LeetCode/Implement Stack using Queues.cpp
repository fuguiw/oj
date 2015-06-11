#include <iostream>
#include <queue>
#include <memory>
using namespace std;

class Stack {
public:
    Stack()
        : q1_(new queue<int>),
          q2_(new queue<int>)
    {
    }

    // Push element x onto stack.
    void push(int x) {
        q1_->push(x);
    }

    // Removes the element on top of the stack.
    void pop(void) {
        if (q1_->empty())
            swap(q1_, q2_);

        while (q1_->size() > 1) {
            q2_->push(q1_->front());
            q1_->pop();
        }

        q1_->pop();
    }

    // Get the top element.
    int top(void) {
        if (q1_->empty())
            swap(q1_, q2_);

        while (q1_->size() > 1) {
            q2_->push(q1_->front());
            q1_->pop();
        }

        return q1_->front();
    }

    // Return whether the stack is empty.
    bool empty(void) {
        return q1_->empty() && q2_->empty();
    }

private:
    shared_ptr<queue<int>> q1_;
    shared_ptr<queue<int>> q2_;
};

int main(int argc, char *argv[])
{
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
