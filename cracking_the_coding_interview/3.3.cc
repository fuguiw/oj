#include <iostream>
#include <vector>
using namespace std;

class SetOfStacks {
    void push(int n)
    {
        if (stack_.empty() || stack_.back().size() == size_)
            stack_.push_back(vector<int>(1, n));
        else
            stack_.back().push_back(n);
    }

    void pop()
    {
        stack_.back().pop_back();
        if (stack_.back().empty())
            stack_.pop_back();
    }

    vector<vector<int>> stack_;
    int size_;

public:
    vector<vector<int>> setOfStacks(vector<vector<int> > ope, int size) {
        stack_.clear();
        size_ = size;
        for (int i = 0; i < ope.size(); ++i)
        {
            if (ope[i][0] == 1)
                push(ope[i][1]);
            else if (ope[i][0] == 2)
                pop();
        }
        return stack_;
    }
}; 

int main(int argc, char *argv[])
{
    SetOfStacks stack;
    vector<vector<int>> ope{{1,1},{1,1},{2,2}};
    stack.setOfStacks(ope, 1);
    return 0;
}
