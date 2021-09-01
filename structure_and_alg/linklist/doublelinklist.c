typedef struct DLinkList {
    int data;
    struct Dlinklist *prior;
    struct Dlinklist *next;
} DLinkList;

DLinkList *CreateDLinklist(int *data, int n)
{
    DLinkList *L = (DLinkList *)malloc(sizeof(DLinkList));
    L->next = L->prior = NULL;
    for (int i = 0; i < n; i++) {
        DLinkList *s = (DLinkList *)malloc(sizeof(DLinkList));
        s->data = data[i];
        s->next = L->next;
        if (L->next != NULL) {
            L->next->prior = s;
        }
        L->next = s;
        s->prior = L;
    }
    return L;
}


DLinkList *CreateDLinklistTail(int *data, int n)
{
    DLinkList *L = (DLinkList *)malloc(sizeof(DLinkList));
    L->next = L->prior = NULL;
    DLinkList *p = L;
    for (int i = 0; i < n; i++) {
        DLinkList *s = (DLinkList*)malloc(sizeof(DLinkList));
        s->data = data[i];
        p->next = s;
        s->prior = p;
        p = s;
    }
    p->next = NULL;
}