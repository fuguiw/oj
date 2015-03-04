#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *f(int num[], int start, int end) {
    int mid;
    struct TreeNode *node;

    if (start > end)
        return NULL;

    mid = (start + end) / 2;

    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    node->val = num[mid];
    node->left = f(num, start, mid - 1);
    node->right = f(num, mid + 1, end);

    return node;
}

struct TreeNode *sortedArrayToBST(int num[], int n) {
    return f(num, 0, n - 1);
}

void print(struct TreeNode *r) {
    if (r == NULL)
        return ;

    printf("%d\n", r->val);
    print(r->left);
    print(r->right);
}

int main(int argc, char *argv[])
{
    int num[] = {1,2,3,4,5,6,7};
    struct TreeNode *root;

    root = sortedArrayToBST(num, 7);

    print(root);

    return 0;
}

