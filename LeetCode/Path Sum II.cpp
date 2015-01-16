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
    vector<int> v;
    vector<vector<int> > vv;

    void f(TreeNode *root, int sum, int t) {
        if (root)
            v.push_back(root->val);
        else
            return ;

        if (root->left == NULL && root->right == NULL) {
            if (sum + root->val == t) {
                vv.push_back(v);
                v.pop_back();
                return;
            } 
        }

        if (root->right)
            f(root->right, sum + root->val, t);

        if (root->left)
            f(root->left, sum + root->val, t);

        v.pop_back();
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        f(root, 0, sum);
        return vv;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    TreeNode n1(2);
    TreeNode n2(1);
    TreeNode n3(3);
    TreeNode n4(3);
    TreeNode n5(1);
    vector<vector<int> > vv;

    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n4;
    n3.left = &n5;
    
    vv = sol.pathSum(&n1, 6);

    for (int i = 0; i < vv.size(); i++)
        for (int j = 0; j < vv[0].size(); j++)
            cout << vv[i][j] << endl;

    return 0;
}
