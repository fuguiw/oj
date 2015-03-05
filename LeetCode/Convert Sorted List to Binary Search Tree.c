#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode *h;

struct TreeNode *f(int start, int end)
{
    int mid;
    struct TreeNode *node;

    if (start > end)
        return NULL;

    mid = (start + end) / 2;

    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->left = f(start, mid - 1);
    node->val = h->val;
    h = h->next;
    node->right = f(mid + 1, end);

    return node;
}

struct TreeNode *sortedListToBST(struct ListNode *head) {
    int num;

    h = head;

    for (num = 0; head; head = head->next)
        ++num;

    return f(0, num - 1);
}

void print(struct TreeNode *r) {
    if (r == NULL)
        return ;

    print(r->left);
    printf("%d\n", r->val);
    print(r->right);
}

int main(int argc, char *argv[])
{
    struct TreeNode *root;
    struct ListNode n1;
    struct ListNode n2;
    struct ListNode n3;
    struct ListNode n4;
    struct ListNode n5;

    n1.val = 1;
    n1.next = &n2;
    n2.val = 2;
    n2.next = &n3;
    n3.val = 3;
    n3.next = &n4;
    n4.val = 4;
    n4.next = &n5;
    n5.val = 5;
    n5.next = NULL;

    root = sortedListToBST(&n1);

    print(root);

    return 0;
}

