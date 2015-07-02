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
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> vv;
        queue<pair<int, TreeNode*>> q;
        if (pRoot)
            q.push(make_pair(1, pRoot));
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (vv.size() < node.first)
                vv.push_back(vector<int>());
            vv[node.first - 1].push_back(node.second->val);
            if (node.second->left)
                q.push(make_pair(node.first + 1, node.second->left));
            if (node.second->right)
                q.push(make_pair(node.first + 1, node.second->right));
        }

        return vv;
    }
};

