/*struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

class Solution {
    bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1 == nullptr)
            return false;
        if (pRoot1->val != pRoot2->val)
            return false;

        bool rnt = true;
        if (pRoot2->left) rnt = rnt && IsSubtree(pRoot1->left, pRoot2->left);
        if (pRoot2->right) rnt = rnt && IsSubtree(pRoot1->right, pRoot2->right);

        return rnt;
    }

public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1 == nullptr || pRoot2 == nullptr)
            return false;

        if (pRoot1->val == pRoot2->val && IsSubtree(pRoot1, pRoot2))
            return true;

        if (pRoot1->left && HasSubtree(pRoot1->left, pRoot2))
            return true;

        if (pRoot1->right && HasSubtree(pRoot1->right, pRoot2))
            return true;

        return false;
    }
};
