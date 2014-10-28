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

class Solution {
private:
	bool is_symmetric(TreeNode *ltree, TreeNode *rtree)
	{
		bool ret;
		if (ltree->val != rtree->val)
			return false;
		if (ltree->left && rtree->right){
			ret = is_symmetric(ltree->left, rtree->right);
			if (!ret) return false;
		} else if (!ltree->left && !rtree->right) {
			ret = true;
		} else {
			return false;
		}
		if (ltree->right && rtree->left){
			ret = is_symmetric(ltree->right, rtree->left);
			if (!ret) return false;
		} else if (!ltree->right && !rtree->left) {
			ret = true;
		} else {
			return false;
		} 
		return true;
	}
public:
	bool isSymmetric(TreeNode *root) {
		if (!root) 
			return true;
		if (!root->left && !root->right) 
			return true;
		if (root->left && root->right) 
			return is_symmetric(root->left, root->right);
		return false;
	}
};

int main()
{
	Solution sol;
	TreeNode root(2);
	TreeNode n1(3);
	TreeNode n2(3);
	TreeNode n3(4);
	TreeNode n4(4);
	TreeNode n5(5);

	root.left = &n1;
	root.right = &n2;
	n1.left = &n3;
	n2.right = &n4;
	/* n2.right = &n4; */

	cout << sol.isSymmetric(&root) << endl;

	return 0;
}
