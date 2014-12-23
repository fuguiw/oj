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
	TreeNode *curr;
public:
    void flatten(TreeNode *root) {
		if (!root)
			return ;

		curr = root;
		TreeNode *right = root->right;

		if (root->left) {
			root->right = root->left;
			root->left = NULL;
			flatten(root->right);
		}

		if (right) {
			curr->right = right;
			curr = right;
			flatten(curr);
		}
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(6);
	TreeNode *n;

	n1.left = &n2;
	n2.left = &n3;
	n2.right = &n4;
	n1.right = &n5;
	n5.right = &n6;

	sol.flatten(&n1);

	for (n = &n1; n; n = n->right)
		cout << n->val << endl;
	return 0;
}

