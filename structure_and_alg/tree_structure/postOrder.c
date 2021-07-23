typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} Node;

void PostOrder(Node *root)
{
    if (root != NULL) {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d", root->val);
    }
}

#define MAXS 1024

void PostOrder(Node *root)
{
    int top, flag;
    top = -1;
    Node *pTmp[MAXS] = {NULL};
    Node *p;
    do {
        while (root != NULL) {
            top++;
            pTmp[top] = root;
            root = root->left;
        }
        p = NULL;
        flag = 1;
        while (top > -1 && flag) {
            root = pTmp[top];
            if (root->right == p) {
                printf("%d", root->val);
                top--;
                p = root;
            } else {
                root = root->right;
                flag = 0;
            }
        }
    } while (top != -1);
}