/*struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pre = nullptr;
        ListNode* curr = pHead;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }

        return pre;
    }
};
