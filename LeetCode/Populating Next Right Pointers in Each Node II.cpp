#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
    void connect(TreeLinkNode *root, vector<TreeLinkNode *>& preNode, int level) {
        if (root == nullptr)
            return ;

        if (preNode.size() < level) {
            preNode.push_back(root);
        } else {
            preNode[level - 1]->next = root;
            preNode[level - 1] = root;
        }

        connect(root->left, preNode, level + 1);
        connect(root->right, preNode, level + 1);
    }

public:
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode *> v;
        connect(root, v, 1);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    TreeLinkNode n1(1);
    TreeLinkNode n2(2);
    TreeLinkNode n3(3);
    TreeLinkNode n4(4);
    TreeLinkNode n5(5);
    TreeLinkNode n6(6);
    TreeLinkNode n7(7);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n7;

    sol.connect(&n1);

    for (TreeLinkNode *r = &n1; r; r = r->left) {
        for (TreeLinkNode *curr = r; curr; curr = curr->next)
            cout << curr->val << endl;
    }

    return 0;
}
