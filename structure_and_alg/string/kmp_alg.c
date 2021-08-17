// kmp 算法关键在求解next数组上

void GetNext(char *pat, int *next)
{
    int j, k;
    j = 0;
    k = -1;
    int m = strlen(pat);
    while (j < m - 1) {
        if (k == -1 || pat[j] == pat[k]) { // 从前向后匹配
            j++;
            k++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

int kmp(char *txt, char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);
    int i, j;
    i = 0;
    j = 0;
    while (i < n && j < m) {
        if (j == -1 || txt[i] == pat[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == m) {
        return i - j;
    }
    return -1; // 没匹配上
}