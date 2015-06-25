class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> st;

        int i, j;
        for (i = j = 0; i < popV.size(); ) {
            if (!st.empty() && st.top() == popV[i]) {
                st.pop();
                ++i;
            } else {
                if (j == pushV.size())
                    break;
                st.push(pushV[j++]);
            }
        }

        if (i == popV.size())
            return true;
        else
            return false;
    }
};
