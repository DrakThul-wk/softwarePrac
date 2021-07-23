typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} Node;


void InOrder(Node *root)
{
	if (root != NULL) {
		InOrder(root->left);
		printf("%d", root->val);
		InOrder(root->right);
	}
 
 }
#define MAXS 1024
 void InOrder(Node *root)
 {
 	int top;
 	Node *pTmp[MAXS] = {NULL};
 	top = -1;
 	Node *p;
 	p = root;
 	while (top > -1 || p != NULL) {
 		while (p != NULL) {
 			top++;
 			pTmp[top] = p;
 			p = p->left;
 		}
 		if (top > -1) {
 			p = pTmp[top];
 			top--;
 			printf("%d", p->val);
 			p = p->right;
 		}
 	}
 }