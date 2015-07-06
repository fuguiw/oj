/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/
class Solution {
    void KthNode(TreeNode* pRoot, unsigned int& k, TreeNode*& node)
    {
        if (pRoot->left)
            KthNode(pRoot->left, k, node);
        if (--k == 0)
            node = pRoot;
        if (k > 0 && pRoot->right)
            KthNode(pRoot->right, k, node);
    }

public:
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        TreeNode* node = nullptr;
        if (pRoot)
            KthNode(pRoot, k, node);
        return node;
    }
};
