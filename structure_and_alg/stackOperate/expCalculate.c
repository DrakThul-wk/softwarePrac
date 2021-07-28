#define MAXS 1024
typedef struct {
    char ch[MAXS];
    int top;
} CharStack;

void ExtractPostexp(char *exp, char *postexp)
{
    CharStack op;
    op.top = -1;
    int i, j;
    i = j = 0;
    while (exp[i] != '\0') {
        switch (exp[i]) {
            case '(':
                op.top++;
                op.ch[op.top] = exp[i];
                break;
            case ')':
                while (op.top != -1 && op.ch[op.top] != '(') {
                    postexp[j++] = op.ch[op.top];
                    op.top--;
                }
                op.top--; // pop '('
                break;
            case '+':
            case '-':
                while (op.top != -1 && op.ch[op.top] != '(') {
                    postexp[j++] = op.ch[op.top];
                    op.top--;
                }
                op.top++;
                op.ch[op.top] = exp[i];
                break;
            case '*':
            case '/':
                while (op.top != -1 && op.ch[op.top] != '(' &&
                       (op.ch[op.top] == '*' || op.ch[op.top] == '/')) {
                    postexp[j++] = op.ch[op.top];
                    op.top--;
                }
                op.top++;
                op.ch[op.top] = exp[i];
                break;
            default:
                while (exp[i] >= '0' && exp[i] <= '9') {
                    postexp[j++] = exp[i];
                    i++;
                }
                postexp[j++] = '#';
                i--;
                break;
        }
        i++;
    }
    while (op.top != -1) {
        postexp[j++] = op.ch[op.top];
        op.top--;
    }
    postexp[j] = '\0';
    return;
}

typedef struct {
    float val[MAXS];
    int top;
} FloatStack;

int CalPostexp(char *postexp) 
{
    int i = 0;
    FloatStack fs;
    fs.top = -1;
    while (postexp[i] != '\0') {
        switch (postexp[i]) {
            case '+':
                fs.val[fs.top - 1] = fs.val[fs.top - 1] + fs.val[fs.top];
                fs.top--;
                break;
            case '-':
                fs.val[fs.top - 1] = fs.val[fs.top - 1] - fs.val[fs.top];
                fs.top++;
                break;
            case '*':
                fs.val[fs.top - 1] = fs.val[fs.top - 1] * fs.val[fs.top];
                fs.top--;
                break;
            case '/': //这里需要注意，加上除0保护
                fs.val[fs.top - 1] = fs.val[fs.top - 1] / fs.val[fs.top];
                break;
            case '#': // ignore
                break;
            default:
                float tmp = 0;
                while (postexp[i] != '\0' && postexp[i] >= '0' && postexp[i] <= '9') {
                    tmp = tmp * 10 + postexp[i] - 48;
                    i++;
                }
                i--;
                fs.top++;
                fs.val[fs.top] = tmp;
                break;
        }
        i++;
    }
    return fs.val[fs.top];
}