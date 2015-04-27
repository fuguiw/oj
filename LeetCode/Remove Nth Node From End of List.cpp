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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int i;
        return do_remove(head, n, i);
    }
private:
    ListNode *do_remove(ListNode *head, int n, int& i) {
        if (head == nullptr) {
            i = 0;
            return head;
        }

        head->next = do_remove(head->next, n, i);
        ++i;

        if (i == n) {
            ListNode *tmp = head->next;
            free(head);
            return tmp;
        }

        return head;
    }
};

