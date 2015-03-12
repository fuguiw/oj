#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> v;
        TreeNode *cur;

        for (cur = root; cur || !st.empty(); ) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            if (!st.empty()) {
                cur = st.top();
                st.pop();
                v.push_back(cur->val);
                cur = cur->right;
            }
        }

        return v;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    vector<int> v;

    n1.right = &n2;
    n2.left = &n3;

    v = sol.inorderTraversal(&n1);

    for (auto i : v)
        cout << i << endl;

    return 0;
}
