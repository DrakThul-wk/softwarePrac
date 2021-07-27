#define MAXSIZE 1024

typedef struct {
    int data[MAXSIZE]
    int top;
} SqStack;


/*初始化栈*/
void InitStack(SqStack *pst)
{
    pst->top = -1;
    return;
}

/* 判断栈是否为空, 返回1为空，返回0为非空 */
int CheckStackEmpty(SqStack *pst)
{
    if (pst->top == -1) {
        return 1;
    }
    return 0;
}

/*返回0则无法入栈，返回1则正常入栈*/
int PushStack(SqStack *pst, int value)
{
    if (pst->top == MAXSIZE - 1) {
        return 0;
    }
    pst->top++;
    pst->data[pst->top] = value;
    return 1;
}

/*返回0则为出栈失败，返回1则出栈成功*/
int PopStack(SqStack *pst, int *value)
{
    if (CheckStackEmpty(pst) == 1) {
        return 0;
    }
    *value = pst->data[pst->top];
    pst->top--;
    return 1;
}

/*返回0无法得到栈顶元素*/
int GetTopStack(SqStack *pst, int *value)
{
    if (CheckStackEmpty(pst) == 1) {
        return 0;
    }
    *value = pst->data[pst->top];
    return 1;
}