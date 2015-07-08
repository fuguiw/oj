#include <iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
}
};
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* fast_node;
        ListNode* slow_node;

        for (fast_node = slow_node = pHead;;) {

            if (fast_node && fast_node->next && fast_node->next->next) {
                fast_node = fast_node->next->next;
                slow_node = slow_node->next;
            } else {
                return nullptr;
            }

            if (fast_node == slow_node)
                break;
        }

        for (fast_node = pHead; ;) {
            if (fast_node == slow_node)
                break;
            fast_node = fast_node->next;
            slow_node = slow_node->next;
        }

        return fast_node;
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
    n5.next = &n3;

    cout << sol.EntryNodeOfLoop(&n1)->val << endl;

    return 0;
}
