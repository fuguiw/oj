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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *h, *pre, *p1, *p2;

        if (head == NULL || head->next == NULL) 
            return head;

        for (h = p1 = head; p1; p1 = p1->next) {
            if (p1->val != h->val) {
                if (p1 == h->next)
                    break;
                else 
                    h = p1;
            }
        }

        if (p1 == NULL && h->next != NULL)
            return NULL;

        p1 = p2 = h->next;
        pre = h;
        pre->next = NULL;
        for (; p2; p2 = p2->next) {
            if (p2->val != p1->val) {
                if (p2 == p1->next) {
                    pre->next = p1;
                    pre = p1;
                    pre->next = NULL;
                } 
                p1 = p2;
            }
        }

        if (p1 && p1->next == NULL)
            pre->next = p1;

        return h;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    ListNode n1(1);
    ListNode n2(1);
    ListNode n3(2);
    ListNode n4(3);
    ListNode n5(4);
    ListNode n6(4);
    ListNode *p;

    n1.next = &n2;
    n2.next = &n3;
    /* n3.next = &n4; */
    /* n4.next = &n5; */
    /* n5.next = &n6; */

    p = sol.deleteDuplicates(&n1);

    for (; p; p = p->next)
        cout << p->val << endl;

    return 0;
}
