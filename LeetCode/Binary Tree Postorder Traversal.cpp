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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        stack<TreeNode *> st;
        TreeNode *cur, *pre;

        if (root)
            st.push(root);
        pre = NULL;

        while (!st.empty()) {
            cur = st.top();

            if ((cur->left == NULL && cur->right == NULL) ||
                    ((pre != NULL) && (pre == cur->left || pre == cur->right))) {
                v.push_back(cur->val);
                st.pop();
                pre = cur;
            } else {
                if (cur->right)
                    st.push(cur->right);
                if (cur->left)
                    st.push(cur->left);
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

    v = sol.postorderTraversal(&n1);

    for (auto i : v)
        cout << i << endl;

    return 0;
}
