《顺序队列》
typedef struct {
    int data[MAXS];
    int front;
    int rear;
} SqQueue;

初始化队列：qu.front == qu.rear = -1;
队列为空的条件：qu.front = qu.rear
队列满的条件：qu.rear == MAXS - 1;
进队：qu.rear = qu.rear + 1; qu.data[qu.rear] = x;
出队：qu.front = qu.front + 1; x = qu.data[qu.front];

