typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} Node;

void PreOrder(Node *root)
{
    if (root != NULL) {
        printf("%d", root->val);
        PreOrder(root->left);
        PreOrder(root->right);
    }
    return;
}

#define MAXS 1024
void PreOrder(Node *root)
{
	Node *pTmp[MAXS] = {NULL};
	Node *p;
	int top;
	top = -1;
	top++;
	pTmp[top] = root;
	while (top > -1) {
		p = pTmp[top];
		printf("%d", p->val);
		top--;
		if (p->right != NULL) {
			top++;
			pTmp[top] = p->right;
		}
		if (p->left != NULL) {
			top++;
			pTmp[top] = p->left;
		}
	}
	return;
}
