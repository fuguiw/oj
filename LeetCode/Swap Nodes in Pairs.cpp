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
    ListNode *swapPairs(ListNode *head) {
		ListNode *first, *second, *pre;

		first = pre = head;
		if (first && first->next)
			head = first->next;

		while (first) {
			second = first->next;

			if (second) {
				pre->next = second;
				first->next = second->next;
				second->next = first;
			}

			pre = first;
			first = first->next;
		}

		return head;
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode *p;

	n1.next = &n2;
	n2.next = &n3;

	p = sol.swapPairs(NULL);

	while (p) {
		cout << p->val;
		p = p->next;
	}
	cout << endl;

	return 0;
}
