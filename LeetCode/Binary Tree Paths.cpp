/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void findPath(vector<string>& paths, string path, TreeNode* root, int level)
    {
        if (root == nullptr)
            return ;

        if (level == 0) {
            path += to_string(root->val);
        } else {
            path += "->" + to_string(root->val);
        }

        if (root->left == nullptr && root->right == nullptr)
            paths.push_back(path);

        findPath(paths, path, root->left, level + 1);
        findPath(paths, path, root->right, level + 1);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        findPath(paths, string(), root, 0);
        return paths;
    }
};
