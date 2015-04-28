#include <iostream>
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
    bool isSymmetric(TreeNode *ltree, TreeNode *rtree) {
        if (ltree == nullptr && rtree == nullptr)
            return true;

        if (ltree && rtree)
            return (ltree->val == rtree->val) 
                && isSymmetric(ltree->left, rtree->right)
                && isSymmetric(ltree->right, rtree->left);

        return false;
    }

public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) 
            return true;
        return isSymmetric(root->left, root->right);
    }
};

int main()
{
    Solution sol;
    TreeNode root(2);
    TreeNode n1(3);
    TreeNode n2(3);
    TreeNode n3(4);
    TreeNode n4(4);
    TreeNode n5(5);

    root.left = &n1;
    root.right = &n2;
    n1.left = &n3;
    n2.right = &n4;
    /* n2.right = &n4; */

    cout << sol.isSymmetric(&root) << endl;

    return 0;
}
