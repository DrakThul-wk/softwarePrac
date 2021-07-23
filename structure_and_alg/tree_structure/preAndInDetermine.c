typedef struct TreeNode {
    char val;
    struct TreeNode *left;
    struct TreeNode *right;
} Node;


Node *CreateTree(char *pre, char *in, int n)
{
    if (n <= 0) {
        return NULL;
    }
    char *p;
    Node *b;
    b = (Node *)malloc(sizeof(Node));
    b->val = *pre;
    for (p = in; p < in + n; p++) {
        if (*p == *pre) {
            break;
        }
    }
    int k = p - in;
    b->left = CreateTree(pre + 1, in, k);
    b->right = CreateTree(pre + k + 1, p + 1, n - k - 1);
    return b;
}