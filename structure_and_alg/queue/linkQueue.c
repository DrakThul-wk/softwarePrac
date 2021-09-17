链队就是采用链式存储结构存储队列，这里采用单链表实现；
链队的优点是不会存在队列满的情况，此时只允许在单链表的表头进行删除操作和在单链表
表尾进行插入操作，因此需要使用两个指针：队首指针front和队尾指针rear。front指向队首节点，
用rear指向队尾节点。
typedef struct QNode {
    int data;
    struct QNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} LinkQueue;

LinkQueue *InitQueue()
{
    LinkQueue *obj = (LinkQueue *)malloc(sizeof(LinkQueue));
    obj->front = obj->rear = NULL;
    return obj;
}

int QueueEmpty(LinkQueue *obj)
{
    return (obj->rear == NULL);
}

void InsertQueue(LinkQueue *obj, int val)
{
    QueueNode *p = (QueueNode *)malloc(sizeof(QueueNode));
    p->data = val;
    p->next = NULL;
    if (obj->rear == NULL) { // only one value
        obj->front = obj->rear = p;
    } else {
        obj->rear->next = p;
        obj->rear = p;
    }
}

void PopQueue(LinkQueue *obj, int *val)
{
    QueueNode *p = obj->front;
    if (obj->rear == NULL) {
        return;
    }
    if (obj->front == obj->rear) {
        obj->front = obj->rear = NULL;
    } else {
        obj->front = obj->front->next;
    }
    *val = p->data;
    free(p);
    p = NULL;
    return;
}
