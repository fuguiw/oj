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
	bool isSame(TreeNode *p, TreeNode *q)
	{
		if (p->val != q->val) return false;
		if (!p->left && !q->left) {
			;
		} else if (p->left && q->left) {
			if (!isSame(p->left, q->left)) return false;
		} else {
			return false;
		}
		if (!p->right && !q->right) {
			;
		} else if (p->right && q->right) {
			if (!isSame(p->right, q->right)) return false;
		} else {
			return false;
		}
		return true;
	}

public:
    bool isSameTree(TreeNode *p, TreeNode *q)
	{
		if (!p && !q) return true;
		if (p && q) return isSame(p, q);
		return false;
    }
};
