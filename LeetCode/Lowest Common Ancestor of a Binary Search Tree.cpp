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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p && q && p->val > q->val)
            swap(p, q);
        TreeNode* ancestor = nullptr;
        queue<TreeNode*> qNode;
        qNode.push(root);

        while (!qNode.empty()) {
            TreeNode* node = qNode.front();
            qNode.pop();
            if (node == nullptr)
                continue;
            if (node->val >= p->val && node->val <= q->val) {
                ancestor = node;
                break;
            }
            if (node->left)
                qNode.push(node->left);
            if (node->right)
                qNode.push(node->right);
        }

        return ancestor;
    }
};
