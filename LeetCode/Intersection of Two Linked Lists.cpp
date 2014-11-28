#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int na, nb;
		ListNode *pa, *pb;

		for (na = 0, pa = headA; pa; pa = pa->next, ++na) ;
		for (nb = 0, pb = headB; pb; pb = pb->next, ++nb) ;

		pa = headA;
		pb = headB;

		if (na > nb) {
			for (int tmp = na - nb; tmp > 0; --tmp, pa = pa->next) ;
		} else {
			for (int tmp = nb - na; tmp > 0; --tmp, pb = pb->next) ;
		}

		for ( ;pa ; pa = pa->next, pb = pb->next)
			if (pa == pb) 
				return pa;

		return NULL;
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	ListNode a(1);
	ListNode *p;
	p = sol.getIntersectionNode(&a, NULL);

	return 0;
}
