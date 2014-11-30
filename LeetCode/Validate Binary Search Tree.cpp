#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	bool _isValidBST(TreeNode *root, bool minFlag, int minVal, bool maxFlag, int maxVal) {
		if (minFlag && root->val <= minVal)
			return false;
		if (maxFlag && root->val >= maxVal)
			return false;
		if (root->left && !_isValidBST(root->left, minFlag, minVal, true, root->val))
			return false;
		if (root->right && !_isValidBST(root->right, true, root->val, maxFlag, maxVal))
			return false;
		return true;
	}

public:
    bool isValidBST(TreeNode *root) {
		if (!root)
			return true;
		if (root->left && !_isValidBST(root->left, false, INT_MIN, true, root->val))
			return false;
		if (root->right && !_isValidBST(root->right, true, root->val, false, INT_MAX))
			return false;
		return true;
    }
};

int main()
{
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	Solution sol;

	n2.left = &n1;
	n2.right = &n3;

	cout << sol.isValidBST(&n2) << endl;

	return 0;
}
