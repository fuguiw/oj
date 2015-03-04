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

/*
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
*/

#define max(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode *root;

int get_height(struct TreeNode *r)
{
    if (r == NULL)
        return -1;

    if (r->left == NULL && r->right == NULL)
        return 0;

    return max(get_height(r->left), get_height(r->right)) + 1;
}

struct TreeNode *single_rotate_left(struct TreeNode *k2)
{
    struct TreeNode *k1;

    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    return k1;
}

struct TreeNode *single_rotate_right(struct TreeNode *k1)
{
    struct TreeNode *k2;

    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    return k2;
}

struct TreeNode *double_rotate_left(struct TreeNode *k3)
{
    k3->left = single_rotate_right(k3->left);

    return single_rotate_left(k3);
}

struct TreeNode *double_rotate_right(struct TreeNode *k3)
{
    k3->right = single_rotate_left(k3->right);

    return single_rotate_right(k3);
}

struct TreeNode *insert(struct TreeNode *r, struct TreeNode *node)
{
    if (r == NULL)
        return node;

    if (node->val < r->val) {
        r->left = insert(r->left, node);
        if (get_height(r->left) - get_height(r->right) == 2) {
            if (node->val < r->left->val)
                r = single_rotate_left(r);
            else
                r = double_rotate_left(r);
        }
    } else if (node->val > r->val) {
        r->right = insert(r->right, node);
        if (get_height(r->right) - get_height(r->left) == 2) {
            if (node->val > r->right->val)
                r = single_rotate_right(r);
            else
                r = double_rotate_right(r);
        }
    }

    return r;
}

struct TreeNode *sortedArrayToBST(int num[], int n) {
    int i;
    struct TreeNode *node;

    root = NULL;

    for (i = 0; i < n; i++) {
        node = (struct TreeNode *)malloc(sizeof(struct TreeNode));

        node->val = num[i];
        node->left = node->right = NULL;

        if (root == NULL) {
            root = node;
            continue ;
        }

        root = insert(root, node);
    }

    return root;
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

