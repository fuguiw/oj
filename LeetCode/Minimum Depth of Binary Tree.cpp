#include <iostream>
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
	struct QueueNode {
		TreeNode *tNode;
		int depth;
	}; 
public:
	int minDepth(TreeNode *root) {
		if (!root) return 0;

		queue<QueueNode> q;
		QueueNode tmp;
		QueueNode qNode; 

		qNode.tNode = root;
		qNode.depth = 1;
		q.push(qNode);

		while (!q.empty()) {
			qNode = q.front();
			q.pop();
			TreeNode *tNode = qNode.tNode;

			if (!tNode->left && !tNode->right) 
				return qNode.depth;
			if (tNode->left) {
				tmp.tNode = tNode->left;
				tmp.depth = qNode.depth + 1;
				q.push(tmp);
			}
			if (tNode->right) {
				tmp.tNode = tNode->right;
				tmp.depth = qNode.depth + 1;
				q.push(tmp);
			}
		}
		return 0;
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

	cout << sol.minDepth(&root) << endl;

	return 0;

}
