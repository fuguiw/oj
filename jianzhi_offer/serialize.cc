#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
    void Serialize(TreeNode* root, ostream& os)
    {
        if (root == NULL)
        {
            os << "$,";
            return ;
        }
        os << root->val << ",";
        Serialize(root->left, os);
        Serialize(root->right, os);
    }

    void Deserialize(TreeNode*& root, istream& is)
    {
        char c;
        is >> c;
        if (c == '$')
        {
            is >> c;
            return ;
        }

        int val = c - '0';
        while (is >> c && c != ',')
            val = val * 10 + c - '0';

        root = new TreeNode(val);
        Deserialize(root->left, is);
        Deserialize(root->right, is);
    }

public:
    char* Serialize(TreeNode* root) {
        ostringstream series;
        Serialize(root, series);
        char* rnt = new char[series.str().size() + 1];
        strncpy(rnt, series.str().c_str(), series.str().size());
        rnt[series.str().size()] = '\0';
        return rnt;
    }

    TreeNode* Deserialize(char *str) {
        TreeNode* root = nullptr;
        istringstream series(str);
        Deserialize(root, series);
        return root;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    TreeNode n1(10);
    TreeNode n2(20);
    TreeNode n3(30);
    n1.left = &n2;
    n1.right = &n3;
    char *str = sol.Serialize(&n1);
    cout << str << endl;
    TreeNode* root = sol.Deserialize(str);
    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->right->val << endl;

    return 0;
}
