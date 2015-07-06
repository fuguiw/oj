#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    void kthSmallest(TreeNode* root, int& k, int& val) {
        if (root->left)
            kthSmallest(root->left, k, val);
        if (--k == 0)
            val = root->val;
        if (k > 0 && root->right)
            kthSmallest(root->right, k, val);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int val;
        kthSmallest(root, k, val);
        return val;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    TreeNode n1(1);
    TreeNode n2(2);

    n2.left = &n1;

    cout << sol.kthSmallest(&n2, 2) << endl;

    return 0;
}
