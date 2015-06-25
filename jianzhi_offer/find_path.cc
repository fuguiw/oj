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
    void FindPath(TreeNode* root, vector<vector<int>>& vv, vector<int> v, int expectNumber) {
        if (root == nullptr)
            return ;

        v.push_back(root->val);
        if (expectNumber == root->val && root->left == nullptr && root->right == nullptr) {
            vv.push_back(v);
            return ;
        }

        if (expectNumber > root->val && root->left) {
            FindPath(root->left, vv, v, expectNumber - root->val);
        }
        if (expectNumber > root->val && root->right) {
            FindPath(root->right, vv, v, expectNumber - root->val);
        }
    }

public:
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> vv;
        vector<int> v;
        FindPath(root, vv, v, expectNumber);
        return vv;
    }
};
