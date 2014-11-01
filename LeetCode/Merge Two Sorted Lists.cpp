#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *head;
		ListNode *entry;

		if (!l1) return l2;
		if (!l2) return l1;

		head = entry = NULL;
		for (; l1 && l2; ) {
			if (l1->val <= l2->val) {
				if (!head) head = l1;
				if (entry) {
					entry->next = l1;
				}
				entry = l1;
				l1 = l1->next;
			} else {
				if (!head) head = l2;
				if (entry) {
					entry->next = l2;
				}
				entry = l2;
				l2 = l2->next;
			}
		}
		if (l1) entry->next = l1;
		else entry->next = l2;
		return head;
    }
};

int main()
{
	ListNode n1(1);
	ListNode n2(4);
	ListNode n3(7);

	ListNode n4(2);
	ListNode n5(4);
	ListNode n6(7);

	n1.next = &n2;
	n2.next = &n3;
	n4.next = &n5;
	n5.next = &n6;

	Solution sol;
	ListNode *head;
	head = sol.mergeTwoLists(&n1, &n4);
	while(head) {
		cout << head->val;
		head = head->next;
	}
	cout << endl;
	return 0;
}
