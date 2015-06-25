/*
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        map<RandomListNode*, RandomListNode*> m;
        m[nullptr] = nullptr;

        RandomListNode* newHead = nullptr;
        RandomListNode** newCurr = &newHead;
        RandomListNode* curr;
        for (curr = pHead; curr; curr = curr->next) {
            *newCurr = new RandomListNode(curr->label);
            m[curr] = *newCurr;
            newCurr = &(*newCurr)->next;
        }

        for (curr = pHead, newCurr = &newHead; curr; curr = curr->next) {
            (*newCurr)->random = m[curr->random];
            newCurr = &(*newCurr)->next;
        }

        return newHead;
    }
};
