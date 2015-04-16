#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
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
public:
    int findMax(TreeNode *root) {
        if (root == NULL)
            return INT_MIN;

        int left = findMax(root->left);
        int right = findMax(root->right);

        int tmax = root->val;
        if (left > 0) tmax += left;
        if (right > 0) tmax += right;
        max_sum = max(max_sum, tmax);

        int ret = root->val;
        int t = max(left, right);
        if (t > 0) ret += t;

        return ret;
    }

    int maxPathSum(TreeNode *root) {
        max_sum = INT_MIN;
        findMax(root);
        return max_sum;
    }

private:
    int max_sum;
};

int main(int argc, char *argv[])
{
    Solution sol;
    TreeNode n1(1);
    TreeNode n2(-2);
    TreeNode n3(3);
    n1.left = &n2;
    n1.right = &n3;

    cout << sol.maxPathSum(&n1) << endl;

    return 0;
}

