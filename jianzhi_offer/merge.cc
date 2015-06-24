#include <iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* head = nullptr;
        ListNode** curr = &head;

        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        while (p1 && p2) {
            if (p1->val > p2->val) {
                *curr = p2;
                curr = &p2->next;
                p2 = p2->next;
            } else {
                *curr = p1;
                curr = &p1->next;
                p1 = p1->next;
            }
        }
        
        if (p1) *curr = p1;
        if (p2) *curr = p2;

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
    n1.next = &n3;
    n3.next = &n5;
    n2.next = &n4;
    n4.next = &n6;

    ListNode* node = sol.Merge(&n1, &n2);
    while (node) {
        cout << node->val << endl;
        node = node->next;
    }
    return 0;
}
