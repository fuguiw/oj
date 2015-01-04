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
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *p1, *p2, *ret;
        int i;

        if (!head)
            return NULL;

        for (i = 0, p2 = head; i < k; i++)
            p2 = p2->next ? p2->next : head;

        for (p1 = head; p2->next; p1 = p1->next, p2 = p2->next) ;

        ret = p1->next ? p1->next : head;
        p2->next = head;
        p1->next = NULL;

        return ret;
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

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    p = sol.rotateRight(&n1, 6);

    for (; p; p = p->next)
        cout << p->val << endl;

    return 0;
}
