/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
		int dl, dr;

		dl = dr = 0;
		if (!root) return 0;
		if (root->left) dl = maxDepth(root->left);
		if (root->right) dr = maxDepth(root->right);

		return max(dl, dr) + 1;
    }
};
