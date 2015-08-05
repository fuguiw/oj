/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        ListNode* phLess = nullptr;
        ListNode* phGreater = nullptr;
        ListNode** pLess = &phLess;
        ListNode** pGreater = &phGreater;

        for (pHead; pHead = pHead->next)
        {
            if (pHead->val < x)
            {
                *pLess = pHead;
                pLess = &pHead->next;
            }
            else
            {
                *pGreater = pHead;
                pGreater = &pHead->next;
            }
        }

        *pLess = phGreater;
        *pGreater = nullptr;
        return phLess;
    }
};
