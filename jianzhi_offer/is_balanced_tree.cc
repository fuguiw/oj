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
    pair<bool, int> IsBalancedTree(TreeNode* pRoot) {
        if (pRoot == nullptr)
            return make_pair(true, 0);

        auto left = IsBalancedTree(pRoot->left);
        auto right = IsBalancedTree(pRoot->right);
         
        bool is_balanced = left.first 
                            && right.first 
                            && (fabs(left.second - right.second) < 2);

        return make_pair(is_balanced, max(left.second, right.second) + 1);
    }

public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return IsBalancedTree(pRoot).first;
    }
};
