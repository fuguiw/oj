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
    ListNode *sortList(ListNode *head, int len) {
        if (len <= 1)
            return head;

        ListNode *curr = head;
        for (int i = 0; i < len / 2; i++) {
            curr = curr->next;
        }

        ListNode *left = sortList(head, len / 2);
        ListNode *right = sortList(curr, len - len / 2);

        head = curr = nullptr;
        int i, j;
        for (i = j = 0; i < len / 2 && j < len - len / 2; ) {
            ListNode *tmp = nullptr;
            if (left->val < right->val) {
                tmp = left;
                left = left->next;
                i++;
            } else {
                tmp = right;
                right = right->next;
                j++;
            }

            if (curr) curr->next = tmp;
            curr = tmp;
            if (head == nullptr) head = curr;
        }

        if (i < len / 2)
            curr->next = left;
        if (j < len - len / 2)
            curr->next = right;

        return head;
    }

public:
    ListNode* sortList(ListNode* head) {
        ListNode *curr;

        int len = 0;
        for (curr = head; curr; curr = curr->next)
            len++;

        head = sortList(head, len);

        curr = head;
        for (int i = 0; i < len - 1; i++)
            curr = curr->next;

        if (curr) curr->next = nullptr;
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

    n2.next = &n1;
    n1.next = &n4;
    n4.next = &n3;

    ListNode *n = sol.sortList(nullptr);

    for (; n; n = n->next)
        cout << n->val << endl;

    return 0;
}

