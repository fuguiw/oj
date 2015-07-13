#include <iostream>
#include <vector>
#include <queue>
#include <utility>
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
    typedef vector<TreeNode*> TreeList;

    void findPath(TreeNode* root, TreeNode* target, TreeList& list, int level, bool& found) {
        if (found)
            return ;

        if (list.size() < level)
            list.push_back(root);
        else
            list[level - 1] = root;

        if (root == target) {
            found = true;
            list.erase(list.begin() + level, list.end());
        }

        if (root->left)
            findPath(root->left, target, list, level + 1, found);
        if (root->right)
            findPath(root->right, target, list, level + 1, found);
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return root;

        TreeList pList, qList;
        bool found = false;
        findPath(root, p, pList, 1, found);
        found = false;
        findPath(root, q, qList, 1, found);

        TreeNode* ancestor = nullptr;
        auto pIt = pList.begin();
        auto qIt = qList.begin();
        while (pIt != pList.end() && qIt != qList.end()) {
            if (*pIt != *qIt)
                break;
            ancestor = *pIt;
            ++pIt;
            ++qIt;
        }

        return ancestor;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    TreeNode n0(0);
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    TreeNode n7(7);
    TreeNode n8(8);
    TreeNode n9(9);
    n3.left = &n5;
    n3.right = &n1;
    n5.left = &n6;
    n5.right = &n2;
    n2.left = &n7;
    n2.right = &n4;
    n1.left = &n0;
    n1.right = &n8;

    cout << sol.lowestCommonAncestor(&n3, &n5, &n4)->val << endl;

    return 0;
}
