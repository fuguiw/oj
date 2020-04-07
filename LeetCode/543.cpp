
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
public:
    void find(TreeNode *root, int &sl, int& ml) {
        if (root == NULL) {
            sl = -1;
            return ;
        }
        int lsl = 0, rsl = 0;
        find(root->left, lsl, ml);
        find(root->right, rsl, ml);
        sl = max(lsl, rsl) + 1;
        ml = max(ml, lsl + rsl + 2);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int sl, ml = 0;
        find(root, sl, ml);
        return ml;
    }
};