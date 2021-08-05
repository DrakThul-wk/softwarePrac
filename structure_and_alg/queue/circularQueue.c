《循环队列》
typedef struct {
    int data[MAXS];
    int front;
    int rear;
} SqQueue;

初始化队列：qu.rear = qu.front = 0;
队列为空时：qu.front = qu.rear;
队列满时：qu.front = (qu.rear + 1) % MAXS;
出队：qu.front = (qu.front + 1) % MAXS; x = qu.data[qu.front];
进队：qu.rear = (qu.rear + 1) % MAXS; qu.data[qu.rear] = x;
