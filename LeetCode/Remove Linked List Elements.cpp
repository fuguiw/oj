/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr, *pre;

        for (curr = head, pre = nullptr; curr; ) {
            ListNode *next = curr->next;
            if (curr->val == val) {
                if (pre)
                    pre->next = next;
                else
                    head = next;
                free(curr);
                curr = nullptr;
            } else {
                pre = curr;
            }

            curr = next;
        }

        return head;
    }
};
