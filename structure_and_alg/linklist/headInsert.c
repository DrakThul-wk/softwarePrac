typedef struct LinklistStruct {
	int val;
	struct LinklistStruct next;
} Linklist;

Linklist *CreateList(int *data, int n)
{
	Linklist *L = (Linklist *)malloc(sizeof(Linklist));
	L->next = NULL;
	Linklist *p;
	for (int i = 0; i < n; i++) {
		p = (Linklist *)malloc(sizeof(Linklist));
		p->val = data[i];
		p->next = L->next;
		L->next = p;
	}
	return L;
}