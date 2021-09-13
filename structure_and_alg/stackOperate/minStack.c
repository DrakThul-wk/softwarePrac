#define MAXS 65536
type struct {
    int val[MAXS];
    int top;
}MinStack;

/** initialize your data structure here */
MinStack *minStackCreate() {
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack *obj, int x) {
    obj->top++;
    obj->val[obj->top] = x;
}

void minStackPop(MinStack *obj) {
    obj->top--;
}

int minStackTop(MinStack *obj) {
    if (obj->top >= 0) {
        return obj->val[obj->top];
    }
    return -1;
}

int minStackGetMin(MinStack *obj) {

}

void minStackFree(MinStack *obj) {

}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack *obj = minStackCreate();
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
