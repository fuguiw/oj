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
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> v;
        
        f(root, 1, v);

        return v;
    }

private:
    void f(TreeNode *root, int level, vector<int> &v) {
        if (root == nullptr)
            return ;

        if (level > v.size())
            v.push_back(root->val);

        f(root->right, level + 1, v);
        f(root->left, level + 1, v);
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
    n2.right = &n5;
    n3.right = &n4;

    vector<int> v = sol.rightSideView(&n1);

    for (auto i : v)
        cout << i << endl;

    return 0;
}

