typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} Node;

#define MAXS 1024
void LevelOrder(Node *root)
{
    int front, rear;
    front = rear = 0;
    Node *pTmp[MAXS] = {NULL};
    Node *p;
    rear++;
    pTmp[rear] = root;
    while (front != rear) {
        front = (front + 1) % MAXS;
        p = pTmp[front];
        printf("%d", p->val);
        if (p->left != NULL) {
            rear++;
            pTmp[rear] = p->left;
        }
        if (p->right != NULL) {
            rear++;
            pTmp[rear] = p->right;
        }
    }

}

进阶，如何一次把一行全部打印出来，考虑len = rear-front