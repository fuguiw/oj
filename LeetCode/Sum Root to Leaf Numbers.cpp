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
	int sum;

	void sumNum(TreeNode *root, int num) {
		if (!root->left && !root->right) {
			sum += num * 10 + root->val;
			return ;
		}

		if (root->left)
			sumNum(root->left, num * 10 + root->val);

		if (root->right)
			sumNum(root->right, num * 10 + root->val);
	}

public:
    int sumNumbers(TreeNode *root) {
		sum = 0;

		if (root)
			sumNum(root, 0);

		return sum;
    }
};
