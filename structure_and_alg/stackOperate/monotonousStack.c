// 求一个元素的右侧的最近比它大的元素位置
// 使用单调栈的方法求解
#include "stdio.h"
#define MAXS 64
int main()
{
    int input[] = { 3, 2, 6, 1, 2, 2};
    int st[MAXS] = {0};
    int result[MAXS] = {0};
    int top = -1;
    for (int i = 0; i < sizeof(input) / sizeof(int); i++) {
        if (top == -1) {
            top++;
            st[top] = i;
        } else {
            if (input[i] <= input[st[top]]) {
                top++;
                st[top] = i;
            } else {
                while (top >= 0) {
                    if (input[i] > input[st[top]]) {
                        result[st[top]] = i + 1;
                        top--;
                    } else {
                        break;
                    }
                }
                top++;
                st[top] = i;
            }
        }
    }
    while (top >= 0) {
        result[st[top]] = 0;
        top--;
    }
    for (int i = 0; i < sizeof(input) / sizeof(int); i++) {
        printf("%d, ", result[i]);
    }
    printf("\n");
    return 0;
}
