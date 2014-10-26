#include <iostream>
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

/* is there any negative num? */
class Solution {
public:
	bool hasPathSum(TreeNode *root, int sum) {
		if (!root) return false;

		if (!root->left && !root->right && sum == root->val)
			return true;

		if (root->left && hasPathSum(root->left, sum - root->val))
			return true;
		if (root->right && hasPathSum(root->right, sum - root->val))
			return true;

		return false;
	}
};

int main()
{
	Solution sol;
	TreeNode root(5);
	TreeNode n1(4);
	TreeNode n2(11);
	TreeNode n3(7);
	TreeNode n4(1);

	root.left = &n1;
	n1.left = &n2;
	n2.left = &n3;
	n2.right = &n4;

	cout << sol.hasPathSum(&root, 22) << endl;

	return 0;
}
