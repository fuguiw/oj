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
    pair<ListNode*, ListNode**> reverseList(ListNode *head) {
        ListNode *curr, *pre;

        for (curr = head, pre = nullptr; curr; ) {
            ListNode *next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }

        return make_pair(pre, &head);
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        int cnt = 0;
        ListNode **pre, *next, *curr;
        pre = &head;
        curr = head;

        while (curr) {
            next = curr->next;

            if (++cnt == k) {
                curr->next = nullptr;
                auto ret = reverseList(*pre);
                *pre = ret.first;
                (*(ret.second))->next = next;
                pre = &(*(ret.second))->next;
                cnt = 0;
            }

            curr = next;
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
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
    ListNode n7(7);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;

    ListNode *h = sol.reverseKGroup(nullptr, 7);

    for (; h; h = h->next)
        cout << h->val << endl;

    return 0;
}

