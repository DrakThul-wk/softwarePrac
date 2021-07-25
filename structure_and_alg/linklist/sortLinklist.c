typedef struct LinklistStruct {
	int val;
	struct LinklistStruct *next;
} Linklist;


Linklist *SortLinklist(Linklist *head)
{
	if (head == NULL) {
		return NULL;
	}
	Linklist *L = (Linklist *)malloc(sizeof(Linklist));
	L->next = head;
	Linklist *p = head->next;
	head->next = NULL;
	Linklist *pre;
	while (p = NULL) {
		head = p->next;
		pre = L;
		while (pre->next != NULL && pre->next->val < p->val) {
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = head;
	}

	pre = L->next;
	free(L);
	L = NULL;
	return pre;

}