#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool isValidBST(TreeNode *root, long long &last_val) {
        if (root == nullptr)
            return true;

        if (isValidBST(root->left, last_val) == false)
            return false;

        if (root->val <= last_val)
            return false;

        last_val = root->val;

        if (isValidBST(root->right, last_val) == false)
            return false;

        return true;
    }

public:
    bool isValidBST(TreeNode *root) {
        long long last_val = static_cast<long long>INT_MIN - 1;
        return isValidBST(root, last_val);
    }
};

int main()
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    Solution sol;

    n2.left = &n1;
    n2.right = &n3;

    cout << sol.isValidBST(&n2) << endl;

    return 0;
}
