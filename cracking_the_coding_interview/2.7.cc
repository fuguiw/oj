#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Palindrome {
    bool isPalindrome(ListNode* pPre, ListNode*& pPost) {
        bool rnt;
        if (pPost == nullptr)
        {
            pPost = pPre;
            return true;
        }
        else if (pPost->next == nullptr)
        {
            pPost = pPre->next;
            return true;
        }
        else
        {
            pPost = pPost->next->next;
            rnt = isPalindrome(pPre->next, pPost);
        }

        rnt = rnt && (pPre->val == pPost->val);
        pPost = pPost->next;
        return rnt;
    }

public:
    bool isPalindrome(ListNode* pHead) {
        return isPalindrome(pHead, pHead);
    }
};

int main(int argc, char *argv[])
{
    Palindrome sol;
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(1);
    n1.next = &n2;
    n2.next = &n3;
    cout << sol.isPalindrome(&n1) << endl;
    return 0;
}
