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
    ListNode *partition(ListNode *head, int x) {
		ListNode *p1, *p2, *h1, *h2;

		p1 = p2 = h1 = h2 = NULL;

		for (; head; head = head->next) {
			if (head->val < x) {
				if (!h1) {
					h1 = p1 = head;
					continue;
				}

				p1->next = head;
				p1 = head;

			} else {
				if (!h2) {
					h2 = p2 = head;
					continue;
				}

				p2->next = head;
				p2 = head;
			}
		}

		if (p1) p1->next = h2;
		else h1 = h2;

		if (p2) p2->next = NULL;

		return h1;
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(2);
	ListNode n4(3);
	ListNode n5(4);
	ListNode n6(5);
	ListNode *p;

	n1.next = &n5;
	n5.next = &n4;
	n4.next = &n2;
	n2.next = &n6;
	n6.next = &n3;

	p = sol.partition(NULL, 3);

	while (p) {
		cout << p->val << endl;
		p = p->next;
	}

	return 0;
}

