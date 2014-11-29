#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *p1, *p2;
		int c1, c2;

		for (p1 = p2 = head, c1 = 1; ;) {
			if (!p2) return NULL;
			p2 = p2->next;
			if (!p2) return NULL;
			if (p1 == p2) break;

			p2 = p2->next;
			p1 = p1->next;
			++c1;
			if (!p2) return NULL;
			if (p1 == p2) break;
		}

		
		for (p2 = p2->next, c2 = 1; p2->next != p1->next; ++c2, p2 = p2->next) ;
		

		p2 = p1->next;
		p1 = head;
		if (c1 > c2) {
			for (int tmp = c1 - c2; tmp > 0; --tmp, p1 = p1->next) ;
		} else {
			for (int tmp = c2 - c1; tmp > 0; --tmp, p2 = p2->next) ;
		}

		for (; ; p1 = p1->next, p2 = p2->next) {
			if (p1 == p2)
				return p1;
		}

		return NULL;
    }
};

int main()
{
	Solution sol;
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode *np;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n1;

	np = sol.detectCycle(&n1);
	cout << np->val << endl;

	return 0;
}

