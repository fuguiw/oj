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
	int get_depth(TreeNode *root) 
	{
		int dl, dr, tmp;

		dl = dr = 0;
		if (!root->left && !root->right) return 1;
		if (root->left) 
			if ((dl = get_depth(root->left)) == -1)
				return -1;
		if (root->right) 
			if ((dr = get_depth(root->right)) == -1)
				return -1;
		tmp = max(dl, dr);
		dr = min(dl, dr);
		dl = tmp;

		if (dl - dr > 1) return -1;
		return dl + 1;
	}

public:
	bool isBalanced(TreeNode *root) {
		if (!root) return true;

		if (get_depth(root) == -1)
			return false;
		return true;
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
	root.right = &n2;
	n1.left = &n3;
	n2.right = &n4;

	cout << sol.isBalanced(&root) << endl;

	return 0;
}
