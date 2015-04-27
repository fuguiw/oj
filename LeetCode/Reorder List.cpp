#include <iostream>
#include <stack>
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
    void reorderList(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast) slow = slow->next;

        stack<ListNode *> st;
        while (slow) {
            st.push(slow);
            slow = slow->next;
        }

        slow = head;
        while (!st.empty()) {
            fast = st.top();
            st.pop();
            ListNode *next = slow->next;
            slow->next = fast;
            fast->next = next;
            slow = next;
        }

        if (slow) slow->next = nullptr;
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
    /* n6.next = &n7; */

    sol.reorderList(nullptr);

    for (ListNode *i = &n1; i; i = i->next)
        cout << i->val << endl;

    return 0;
}

