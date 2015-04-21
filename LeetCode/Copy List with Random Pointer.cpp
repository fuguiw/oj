#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr)
            return head;

        RandomListNode *curr, *next;

        for (curr = head; curr; ) {
            next = curr->next;
            RandomListNode *tmp = new RandomListNode(curr->label);
            curr->next = tmp;
            tmp->next = next;
            curr = next;
        }

        for (curr = head; curr; ) {
            next = curr->next;
            if (curr->random)
                next->random = curr->random->next;
            curr = next->next;
        }

        RandomListNode *copy_head, *copy_curr;;
        copy_head = copy_curr = head->next;
        for (curr = head; copy_curr->next; ) {
            curr->next = copy_curr->next;
            curr = curr->next;
            copy_curr->next = curr->next;
            copy_curr = copy_curr->next;
        }
        curr->next = nullptr;

        return copy_head;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    RandomListNode n1(-1);
    RandomListNode n2(2);
    RandomListNode n3(3);

    n1.next = &n2;

    RandomListNode *n = sol.copyRandomList(&n1);
    
    for (; n; n = n->next)
        cout << n->label << " " << endl;

    return 0;
}

