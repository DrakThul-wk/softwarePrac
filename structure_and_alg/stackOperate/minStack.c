#define MAXS 65536
type struct {
    int val1[MAXS];
    int top1;
    int val2[MAXS];
    int top2;
}MinStack;

/** initialize your data structure here */
MinStack *minStackCreate() {
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void minStackPush(MinStack *obj, int x) {
    obj->top1++;
    obj->val1[obj->top1] = x;
    if (obj->top2 == -1) {
        obj->top2++;
        obj->val2[obj->top2] = x;
    } else {
        if (x <= obj->val2[obj->top2]) {
            obj->top2++;
            obj->val2[obj->top2] = x;
        }
    }
}

void minStackPop(MinStack *obj) {
    if (obj->top1 == -1) {
        return;
    }
    int valTmp = obj->val1[obj->top1];
    obj->top1--;
    if (obj->val2[obj->top2] == valTmp) {
        obj->top2--;
    }
}

int minStackTop(MinStack *obj) {
    if (obj->top1 >= 0) {
        return obj->val1[obj->top1];
    }
    return -1;
}

int minStackGetMin(MinStack *obj) {
    if (obj->top2 >= 0) {
        return obj->val2[obj->top2];
    }
    return -1;
}

void minStackFree(MinStack *obj) {
    if (obj == NULL) {
        return;
    }
    free(obj);
    obj = NULL;
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
