typedef struct LinklistStruct {
	int val;
	struct LinklistStruct *next;
} Linklist;

Linklist *CreateList(int *data, int n)
{
	Linklist *L = (Linklist *)malloc(sizeof(Linklist));
	L->next = NULL;
	Linklist *pre = L;
	Linklist *p;
	for (int i = 0; i < n; i++) {
		p = (Linklist *)malloc(sizeof(Linklist));
		p->val = data[i];
		pre->next = p;
		pre = pre->next;
	}
	pre->next = NULL;
	return L;
}