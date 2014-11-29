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
    bool hasCycle(ListNode *head) {
		ListNode *p1, *p2;

		for (p1 = p2 = head; ;) {
			if (!p2) return false;
			p2 = p2->next;
			if (!p2) return false;
			p2 = p2->next;
			p1 = p1->next;
			if (!p2) return false;
			if (p1 == p2) return true;
		}
    }
};
