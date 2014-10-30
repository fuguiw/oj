#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		ListNode *node;
		ListNode *pre;

		if (!head) return head;
		if (!head->next) return head;
		pre = head;
		node = head->next;
		while (node) {
			if (pre->val == node->val) {
				pre->next = node->next;
				free(node);
				node = pre->next;
			} else {
				pre = node;
				node = node->next;
			}
		}
		return head;
    }
};

int main()
{
	Solution sol;
	sol.deleteDuplicates(NULL);
	return 0;
}
