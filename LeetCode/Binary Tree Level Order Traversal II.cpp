#include <iostream>
#include <vector>
#include <queue>
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
	vector<vector<int> > traversal;
	vector<int> level_val;

	void dfs(TreeNode *root, int level)
	{
		if (level >= traversal.size())
			traversal.push_back(level_val);

		traversal[level].push_back(root->val);
		if (root->left) dfs(root->left, level + 1);
		if (root->right) dfs(root->right, level + 1);
	}
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > ret;
		vector<vector<int> >::iterator it;

		if (!root)
			return ret;

		dfs(root, 0);

		for(it = traversal.end() - 1; it >= traversal.begin(); it--)
			ret.push_back(*it);

		return ret;
	}
};

int main()
{
	vector<vector<int> > v;
	vector<vector<int> >::iterator it;
	vector<int> vec;
	vector<int>::iterator i;
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

	v = sol.levelOrderBottom(&root);

	for(it = v.begin(); it < v.end(); it++) {
		for(i = (*it).begin(); i < (*it).end(); i++)
			cout << *i << " ";
		cout << endl;
	}

	return 0;
}
