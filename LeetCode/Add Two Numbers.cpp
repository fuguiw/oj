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
        return do_add(l1, l2, 0);
    }

private:
    ListNode *do_add(ListNode *l1, ListNode *l2, int carry) {
        if (l1 == nullptr && l2 == nullptr && carry == 0)
            return nullptr;

        ListNode *node = new ListNode(0);
        if (l1) node->val += l1->val;
        if (l2) node->val += l2->val;
        node->val += carry;

        carry = node->val / 10;
        node->val %= 10;

        node->next = do_add(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, carry);
        return node;
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
