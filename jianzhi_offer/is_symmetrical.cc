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
    bool isSymmetrical(TreeNode* left_root, TreeNode* right_root)
    {
        if (left_root == nullptr && right_root == nullptr)
            return true;
        if (left_root && right_root && left_root->val == right_root->val)
            return isSymmetrical(left_root->left, right_root->right)
                     && isSymmetrical(left_root->right, right_root->left);
        return false;
    }
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot)
            return isSymmetrical(pRoot->left, pRoot->right);
        return true;
    }

};
