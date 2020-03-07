class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        for (Node *cur = head; cur != NULL; cur = cur->next->next) {
            Node *n = new Node(cur->val);
            n->next = cur->next;
            n->random = cur->random;
            cur->next = n;
        }
        
        for (Node *cur = head->next; cur != NULL; cur = cur->next->next) {
            //cout << cur->random<< endl;
            if (cur->random != NULL)
                cur->random = cur->random->next;
            //cout << cur->random << endl;
            if (cur->next == NULL) break;
        }

        Node *ans = head->next;
        for (Node *cur = head; cur != NULL; cur = cur->next) {
            Node *n = cur->next;     
            cur->next = cur->next->next;
            if (n->next != NULL) {
                n->next = n->next->next;
            }
        }

        return ans;
    }
};
