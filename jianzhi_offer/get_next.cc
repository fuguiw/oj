#include "tools.h"
using namespace std;
/*
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
		
	}
};
*/
class Solution {
    TreeLinkNode* GetMostLeft(TreeLinkNode* root)
    {
        while (root->left)
            root = root->left;
        return root;
    }

public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == nullptr)
            return pNode;

        if (pNode->right) {
            return GetMostLeft(pNode->right);
        }

        if (pNode->next && pNode->next->left == pNode)
            return pNode->next;

        while (pNode->next) {
            if (pNode->next->left == pNode)
                return pNode->next;
            pNode = pNode->next;
        }

        return nullptr;
    }
};
