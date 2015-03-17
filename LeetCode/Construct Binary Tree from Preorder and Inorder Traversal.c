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

struct TreeNode *construct(int *start_pre, int *start_in, int *end_in)
{
    struct TreeNode *root;
    int *i;
    int left_len;

    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = start_pre[0];
    root->left = root->right = NULL;

    for (i = start_in; i <= end_in; i++)
        if (*i == start_pre[0])
            break;

    left_len = i - start_in;

    if (left_len)
        root->left = construct(start_pre + 1, start_in, i - 1);

    if (left_len < end_in - start_in)
        root->right = construct(start_pre + left_len + 1, i + 1, end_in);

    return root;
}

struct TreeNode *buildTree(int *preorder, int *inorder, int n) {
    if (preorder == NULL || inorder == NULL | n <= 0)
        return NULL;

    return construct(preorder, inorder, inorder + n - 1);
}

void print(struct TreeNode *node)
{
    if (node == NULL)
        return ;

    print(node->left);
    printf("%d\n", node->val);
    print(node->right);
}

int main(int argc, char *argv[])
{
    struct TreeNode *node;
    int pre[] = {1,2,4,7,3,5,6,8};
    int in[] = {4,7,2,1,5,3,8,6};

    node = buildTree(pre, in, 8);
    print(node);

    return 0;
}

