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
    ListNode *insertionSortList(ListNode *head) {
		ListNode *p, *h, *node, *tmp;

		if (!head) 
			return NULL;
		
		h = head;
		head = head->next;
		h->next = NULL;

		for (; head; ) {
			node = head;
			head = head->next;

			if (node->val <= h->val) {
				node->next = h;
				h = node;
				continue;
			}

			for (p = h; p->next; p = p->next)
				if (node->val <= p->next->val)
					break;

			tmp = p->next;
			p->next = node;
			node->next = tmp;
		}

		return h;
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	ListNode *p;

	n2.next = &n1;
	
	p = sol.insertionSortList(&n2);

	while (p) {
		cout << p->val << endl;
		p = p->next;
	}

	return 0;
}

