#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        if (fast == nullptr || fast->next == nullptr)
            return nullptr;

        for (fast = head; fast != slow; fast = fast->next, slow = slow->next);

        return fast;
    }
};

int main()
{
    Solution sol;
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode *np;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n1;

    np = sol.detectCycle(&n1);
    cout << np->val << endl;

    return 0;
}

