/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class TreeLevel {
    void getTreeLevel(TreeNode* root, 
                        ListNode*& head, ListNode*& curr, 
                        int curr_dep, int dep) {
        if (root == nullptr)
            return ;
        if (curr_dep < dep) {
            getTreeLevel(root->left, head, curr, curr_dep + 1, dep);
            getTreeLevel(root->right, head, curr, curr_dep + 1, dep);
        } else if (curr_dep == dep) {
            if (head == nullptr) {
                head = new ListNode(root->val);
                curr = head;
            } else {
                curr->next = new ListNode(root->val);
                curr = curr->next;
            }
        }
    }
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        getTreeLevel(root, head, curr, 1, dep);
        return head;
    }
};
