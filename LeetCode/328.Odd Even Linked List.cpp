//
// Created by Kyne on 1/16/16.
//

#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)
            return head;

        ListNode *even_head = head->next;
        ListNode *odd_curr = head;
        ListNode *even_curr = even_head;

        for (; odd_curr && even_curr; ) {
            ListNode *next = even_curr->next;
            if (next == NULL) {
                break;
            }
            odd_curr->next = next;
            odd_curr = odd_curr->next;

            next = odd_curr->next;
            even_curr->next = next;
            even_curr = even_curr->next;
        }

        odd_curr->next = even_head;
        return head;
    }
};

