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

		if (!head) return head;

		ListNode *end = head;
		ListNode *curr = head;

		for (int i = 0; i < n; i++) {
			if (!end->next) {
				return head->next;
			}
			end = end->next;
		}

		for (; end->next; ) {
			end = end->next;
			curr = curr->next;
		}

		curr->next = curr->next->next;
		return head;
    }
};

