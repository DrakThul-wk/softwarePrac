typedef struct TreeNode {
    char val;
    struct TreeNode *left;
    struct TreeNode *right;
} Node;


Node *CreateTree(char *post, char *in, int n)
{
    if (n <= 0) {
        return NULL;
    }
    char *p, r;
    r = *(post + n - 1);
    Node *b;
    b = (Node *)malloc(sizeof(Node));
    b->val = r;
    for (p = in; p < in + n; p++) {
        if (*p == r) {
            break;
        }
    }
    int k = p - in;
    b->left = CreateTree(post, in, k);
    b->right = CreateTree(post + k, p + 1, n - k - 1);
    return b;
}