#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    bool isPalindrome(ListNode*& front, ListNode* back) {
        bool rnt = true;
        if (back->next)
            rnt = isPalindrome(front, back->next);

        rnt = rnt && (front->val == back->val);
        front = front->next;

        return rnt;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head)
            return isPalindrome(head, head);
        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(1);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    cout << sol.isPalindrome(&n1) << endl;

    return 0;
}

