#include <stack>
#include <iostream>
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

class BSTIterator {
public:
    stack<TreeNode *> s;

    BSTIterator(TreeNode *root) {
        for (; root; root = root->left)
            s.push(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *n = s.top();
        s.pop();

        for (TreeNode *t = n->right; t; t = t->left)
            s.push(t);

        return n->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
int main(int argc, char *argv[])
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);

    n1.right = &n2;
    n3.left = &n1;
    n3.right = &n4;

    BSTIterator it = BSTIterator(&n3);
    while (it.hasNext())
        cout << it.next() << endl;
    

    return 0;
}
