// 在定义一个过程或函数时出现调用本过程或本函数的成分，称之为递归

// 尾递归，类似如下：
int fun(int n)
{
    if (n == 1) {
        return 1;
    } else {
        return n * fun(n - 1);
    }

}

// 递归算法的两个基本特性：
// （1）是一种分而治之的方法，把复杂问题分解为简单的问题的求解问题方法；
// （2）一般递归算法的时间效率通常比较差，可以采用手工方法把递归算法转换为非递归算法；

// 递归方法转换为非递归算法一般有两种方法：
// （1）对于尾递归和单向递归，可用循环结构的算法替代；
// （2）利用栈模拟系统的运行，通过分析只保存必要的信息，从而用非递归算法替代递归算法；
int fun(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++) {
        f = f * n;
    }
    return f;
}


// fibonacci(兔子序列)
// 0，1，1，2，3，5，8，13......
int fib(int n)
{
    int i, f1, f2, f3;
    if (n == 1 || n == 2) {
        return 1;
    }
    f1 = f2 = 1;
    for (i >= 3; i <= n; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}

// 利用栈消除递归
// 求解n!
typedef struct {
    int vn;
    int vf;
    int tag;
} StackStructure;

int fun(int n)
{
    int top = -1;
    top++;
    StackStructure st[MAXS];
    st[top].vn = n;
    st[top].tag = 1;
    while (top > -1) {
        if (st[top].tag == 1) { //压栈
            if (st[top].vn == 1) {
                st[top].vf = 1;
                st[top].tag = 0;
            } else {
                top++;
                st[top].vn = st[top - 1].vn - 1;
                st[top].tag = 1;
            }
        } else { // 出栈计算
            st[top - 1].vf = st[top - 1].vn * st[top].vf;
            top--;
            st[top].tag = 0;
        }
        if (top == 0 && st[top].tag == 0) {
            break;
        }
    }
    return st[top].vf;

}


void hanoi(int n, char x, char y, char z)
{
    if (n == 1) {
        printf("第%d个盘子从%c移动到%c\n", n, x, z);
        return;
    }
    hanoi(n - 1, x, z, y);
    printf("第%d个盘子从%c移动到%c\n", n, x, z);
    hanoi(n - 1, y, x, z);
}

typedef struct {
    int n;
    char x;
    char y;
    char z;
    int tag;
} HanoiStack;

void haoni(int n, char a, char b, char c)
{
    HanoiStack stack[MAXS];
    int top = -1;
    top++;
    stack[top].x = a;
    stack[top].y = b;
    stack[top].z = c;
    stack[top].n = n;
    stack[top].tag = 1;
    while (top > - 1) {
        if (stack[top].tag == 1) {
            if (stack[top].n == 1) {
                stack[top].tag = 0;
            } else {
                a = stack[top].x; b = stack[top].y; c = stack[top].z;
                int num = stack[top].n
                top--;
                top++;
                stack[top].x = b;
                stack[top].y = a;
                stack[top].z = c;
                stack[top].n = num - 1;
                stack[top].tag = 1;
                top++;
                stack[top].x = a;
                stack[top].z = c;
                stack[top].n = num;
                stack[top].tag = 0;
                top++;
                stack[top].x = a;
                stack[top].y = c;
                stack[top].z = b;
                stack[top].n = num - 1;
                stack[top].tag = 1;
            }
        } else if (top > -1 && stack[top].tag == 0){
            printf("第%d个盘子从%c移动到%c\n", stack[top].n, stack[top].x, stack[top].z);
            top--;
        }
    }
}