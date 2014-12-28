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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p1, *p2, *h;
        int c = 0;

        p2 = l2;

        for (h = p1 = l1; l1 && l2; l1 = l1->next, l2 = l2->next) {
            p1->val = l1->val + l2->val + c;
            c = p1->val / 10;
            p1->val %= 10;

            if (l1->next && l2->next)
                p1 = p1->next;
        }

        if (l2)
            p1->next = l2;

        if (l1 || l2) {
            p1 = p1->next;
            p1->val += c;
            c = p1->val / 10;
            p1->val %= 10;
            if (c && !p1->next) {
                p1->next = p2;
                p2->val = 0;
                p2->next = NULL;
            }
            p1 = p1->next;
        }

        for (; p1; p1 = p1->next) {
            if (l1 || l2) {
                p1->val += c;
                c = p1->val / 10;
                p1->val %= 10;
            }
            if (c && !p1->next) {
                p1->next = p2;
                p2->val = 1;
                p2->next = NULL;
                break;
            }
        }

        return h;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    ListNode n1(9);
    ListNode n2(9);
    ListNode n3(9);

    ListNode n4(1);
    ListNode n5(5);
    ListNode n6(7);
    ListNode *p;

    n1.next = &n2;
    /* n2.next = &n3; */

    p = sol.addTwoNumbers(&n1, &n4);

    while (p) {
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}
