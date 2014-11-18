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
private:
	vector<int> traversal; 
	void _preorderTraversal(TreeNode *root) {
		if (!root)
			return ;

		traversal.push_back(root->val);
		if (root->left)
			_preorderTraversal(root->left);
		if (root->right)
			_preorderTraversal(root->right);
	}
public:
    vector<int> preorderTraversal(TreeNode *root) {
		traversal.clear();
		_preorderTraversal(root);
		return traversal;
    }
};
