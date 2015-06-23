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
    struct TreeNode* reConstructBinaryTree(const vector<int>& pre, 
                                           const vector<int>& in,
                                           int& pre_idx, int in_begin, int in_end)
    {
        if (pre_idx == pre.size())
            return nullptr;

        int i;
        for (i = in_begin; i != in_end; i++)
            if (in[i] == pre[pre_idx])
                break;

        TreeNode* root = new TreeNode(pre[pre_idx]);
        ++pre_idx;

        if (i > in_begin)
            root->left = reConstructBinaryTree(pre, in, pre_idx, in_begin, i);
        if (i < in_end - 1)
            root->right = reConstructBinaryTree(pre, in, pre_idx, i + 1, in_end);

        return root;
    }

public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        int pre_idx = 0;
        TreeNode* root = reConstructBinaryTree(pre, in, pre_idx, 0, pre.size());
        return root;
    }
};


int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> pre{1,2,3,4,5,6,7};
    vector<int> in{3,2,4,1,6,5,7};

    TreeNode* root = sol.reConstructBinaryTree(pre, in);

    return 0;
}
