#include <iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
        }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode** curr = &pHead;
        bool del_flag = false;
        while (*curr) {
            ListNode* entry = *curr;
            ListNode* next = (*curr)->next;
            if (next && next->val == entry->val) {
                del_flag = true;
                *curr = next;
            } else if (del_flag) {
                del_flag = false;
                *curr = next;
            } else {
                curr = &entry->next;
            }
        }
        return pHead;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(2);
    ListNode n4(3);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    ListNode* node = sol.deleteDuplication(&n1);
    while (node) {
        cout << node->val << endl;
        node = node->next;
    }

    return 0;
}
