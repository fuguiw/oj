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
    TreeNode *mostRight(TreeNode *root, int h) {
        while (--h)
            root = root->right;
        return root;
    }

    void countNodes(TreeNode *root, int h, int n, int &count) {
        if (root->left) {
            if (root->right) {
                if (mostRight(root->left, h - 1))
                    countNodes(root->right, h - 1, n * 2 + 1, count);
                else
                    countNodes(root->left, h - 1, n * 2, count);
            } else {
                count = n * 2;
            }
        } else {
            if (h > 1) count = (n - 1) * 2 + 1;
            else count = n;
        }
    }

public:
    int countNodes(TreeNode *root) {
        if (root == nullptr) return 0;

        int h = 0;
        for (TreeNode *curr = root; curr; curr = curr->left)
            ++h;

        int count = 1;
        countNodes(root, h, 1, count);

        return count;
    }
};

int main(int argc, char *argv[])
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    TreeNode n7(7);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    /* n3.left = &n6; */
    /* n3.right = &n7; */
    Solution sol;

    cout << sol.countNodes(&n1) << endl;

    return 0;
}
