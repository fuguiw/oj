#include <iostream>
#include <vector>
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
    void zigzagLevelOrder(vector<vector<int>> &vv, TreeNode *root, int level) {
        if (root == nullptr)
            return ;

        if (vv.size() <= level)
            vv.push_back(vector<int>());

        if (level % 2 == 0)
            vv[level].push_back(root->val);
        else
            vv[level].insert(vv[level].begin(), root->val);

        zigzagLevelOrder(vv, root->left, level + 1);
        zigzagLevelOrder(vv, root->right, level + 1);
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vv;

        zigzagLevelOrder(vv, root, 0);

        return vv;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);

    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n4;
    n3.right = &n5;

    vector<vector<int>> vv = sol.zigzagLevelOrder(&n1);

    for (auto &v : vv)
        for (auto i : v)
            cout << i << endl;

    return 0;
}
