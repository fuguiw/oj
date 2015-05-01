#include <iostream>
#include <vector>
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
    vector<TreeNode *> generateTrees(int start, int end) {
        if (start > end)
            return vector<TreeNode *>{nullptr};

        vector<TreeNode *> ret;
        for (int i = start; i <= end; i++) {
            auto left_subtree = generateTrees(start, i - 1);
            auto right_subtree = generateTrees(i + 1, end);

            for (auto left_root : left_subtree) {
                for (auto right_root : right_subtree) {
                    TreeNode *node = new TreeNode(i);
                    node->left = left_root;
                    node->right = right_root;
                    ret.push_back(node);
                }
            }
        }

        return ret;
    }

public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }
};

void print(TreeNode *root)
{
    if (root == nullptr)
        return ;

    cout << root->val;
    print(root->left);
    print(root->right);
}

int main(int argc, char *argv[])
{
    Solution sol;
    
    auto trees = sol.generateTrees(4);

    for (auto r : trees) {
        print(r);
        cout << endl;
    }

    return 0;
}

