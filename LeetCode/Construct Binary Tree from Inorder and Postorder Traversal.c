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

struct TreeNode *construct(int *end_post, int *start_in, int *end_in)
{
    struct TreeNode *root;
    int *i;
    int right_len;

    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = end_post[0];
    root->left = root->right = NULL;

    for (i = start_in; i <= end_in; i++)
        if (*i == end_post[0])
            break;

    right_len = end_in - i;

    if (right_len < end_in - start_in)
        root->left = construct(end_post - right_len - 1, start_in, i - 1);

    if (right_len)
        root->right = construct(end_post - 1, i + 1, end_in);

    return root;
}

struct TreeNode *buildTree(int *inorder, int *postorder, int n) {
    if (inorder == NULL || postorder == NULL | n <= 0)
        return NULL;

    return construct(postorder + n - 1, inorder, inorder + n - 1);
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

