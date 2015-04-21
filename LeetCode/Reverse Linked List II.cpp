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
        ListNode *reverseBetween(ListNode *head, int m, int n) {
            ListNode *node = head;
            ListNode *pre = nullptr;

            for (int i = 1; i < m; ++i, node = node->next)
                pre = node;

            if (pre) {
                pre->next = reverseBetween(node, 1, n - m + 1);
                return head;
            }

            ListNode *next;
            for (int i = 1; i <= n; ++i) {
                next = node->next;
                node->next = pre;
                pre = node;
                node = next;
            }

            head->next = next;
            head = pre;

            return head;
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

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    ListNode *h = sol.reverseBetween(&n1, 2, 4);

    for (; h; h = h->next)
        cout << h->val << endl;

    return 0;
}
