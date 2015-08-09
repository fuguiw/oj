/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Successor {
    void findSucc(TreeNode* root, int p, int& label, int &succ) {
        if (root == nullptr || label == 2)
            return ;
        findSucc(root->left, p, label, succ);
        if (label == 1) {
            label = 2;
            succ = root->val;
        }
        if (root->val == p)
            label = 1;
        findSucc(root->right, p, label, succ);
    }

public:
    int findSucc(TreeNode* root, int p) {
        int label = 0;
        int succ = -1;
        findSucc(root, p, label, succ);
        return succ;
    }
};
