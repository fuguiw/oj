#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
        }
};

class Solution {
    TreeNode* Convert(TreeNode*& pre, TreeNode* root)
    {
        TreeNode* ret = root;

        if (root->left)
            ret = Convert(pre, root->left);

        root->left = pre;
        if (pre) pre->right = root;

        pre = root;

        if (root->right)
            Convert(pre, root->right);

        return ret;
    }

public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* pre = nullptr;
        if (pRootOfTree)
            return Convert(pre, pRootOfTree);
        return nullptr;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);

    /* n2.left = &n1; */
    n1.right = &n3;
    n3.left = &n2;

    TreeNode* root = sol.Convert(&n1);

    for (; root; root = root->right)
        cout << root->val << endl;

    return 0;
}
