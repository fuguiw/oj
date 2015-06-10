#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void traversal(TreeNode* root, TreeNode** pre, TreeNode** node1, TreeNode** node2) {
        if (root == nullptr)
            return ;

        traversal(root->left, pre, node1, node2);

        if (*pre && (*pre)->val > root->val) {
            if (*node1 == nullptr)
                *node1 = *pre;
            *node2 = root;
        }
        *pre = root;

        traversal(root->right, pre, node1, node2);
    }

public:
    void recoverTree(TreeNode* root) {
        TreeNode* node1 = nullptr;
        TreeNode* node2 = nullptr;
        TreeNode* pre = nullptr;

        traversal(root, &pre, &node1, &node2);

        swap(node1->val, node2->val);
    }
};

void print(TreeNode* root)
{
    if (root) {
        print(root->left);
        cout << root->val << endl;
        print(root->right);
    }
}

int main(int argc, char *argv[])
{
    Solution sol;
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    n1.left = &n2;
    sol.recoverTree(&n1);

    print(&n1);

    return 0;
}
