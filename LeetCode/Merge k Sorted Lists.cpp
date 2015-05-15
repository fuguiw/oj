#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
    bool operator()(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (auto l : lists)
            if (l)
                pq.push(l);

        ListNode *head = nullptr;
        ListNode **curr = &head;
        while (!pq.empty()) {
            ListNode *entry = pq.top();
            pq.pop();
            if (entry->next)
                pq.push(entry->next);
            *curr = entry;
            curr = &entry->next;
        }
        *curr = nullptr;

        return head;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<ListNode *> v;

    ListNode n1(1);
    ListNode n2(4);
    n1.next = &n2;
    v.push_back(&n1);

    ListNode n3(2);
    ListNode n4(3);
    ListNode n5(4);
    n3.next = &n4;
    n4.next = &n5;
    v.push_back(&n3);
    
    ListNode n6(1);
    ListNode n7(5);
    ListNode n8(6);
    n6.next = &n7;
    n7.next = &n8;
    v.push_back(&n6);

    ListNode *l = sol.mergeKLists(v);

    for (; l; l = l->next)
        cout << l->val << endl;

    return 0;
}
