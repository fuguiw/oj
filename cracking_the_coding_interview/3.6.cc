class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        stack<int> nums;
        stack<int> st;
        for (int i = numbers.size() - 1; i >= 0; --i)
            nums.push(numbers[i]);

        while (!nums.empty())
        {
            int num = nums.top();
            nums.pop();
            while (!st.empty() && st.top() > num)
            {
                nums.push(st.top());
                st.pop();
            }
            st.push(num);
        }

        numbers.clear();
        while (!st.empty())
        {
            numbers.push_back(st.top());
            st.pop();
        }
        return numbers;
    }
};
