#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* p1 = pListHead;
        while (k-- && p1)
            p1 = p1->next;
        if (k + 1 > 0)
            return NULL;

        ListNode* kth = pListHead;
        while (p1) {
            p1 = p1->next;
            kth = kth->next;
        }

        return kth;
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

    cout << sol.FindKthToTail(&n1, 6)->val << endl;

    return 0;
}
