// boyer moore算法有两种规则，一种是坏字符规则；一种是好后缀规则

#define NO_OF_CHARS 256
int maxCmp(int a, int b)
{
    return ((a > b)? a : b);
}

void GetBcTable(char *pat, int *bc)
{
    int m = strlen(pat);
    for (int i = 0; i < NO_OF_CHARS; i++) {
        bc[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        bc[pat[i]] = i;
    }
}

void GetMsTable(char *pat, int *ms)
{
    int m = strlen(pat);
    ms[m - 1] = m;
    int upper, lower;
    lower = m - 1;
    for (int i = m - 2; i >= 0; i--) {
        if (i > lower && ms[i + m - 1 - upper] < i - lower) {
            ms[i] = ms[i + m - 1 - upper];
        } else {
            if (i < lower) {
                lower = i;
            }
            upper = i;
            while (lower >= 0 && pat[lower] == pat[lower + m - 1 - upper]) {
                lower--;
            }
            ms[i] = upper - lower;
        }
    }
}

void GetGsTable(char *pat, int *gs)
{
    int m = strlen(pat);
    int *ms = (int *)malloc(sizeof(int) * m);
    GetMsTable(pat, ms);
    for (int i = 0; i < m; i++) {
        gs[i] = m;
    }
    int j = 0;
    for (int i = m - 1; i >= 0; i--) {
        if (ms[i] == i + 1) {
            while (j < m - 1 - i) { // " ABCDAB " case1匹配的在前面
                gs[j] = m - 1 - i;
            }
        }
    }
    for (int i = 0; i < m - 1; i++) { // "CDABAB" case2匹配的在中间
        gs[m - 1 - ms[i]] = m - 1 - i;
    }
    free(ms);
    ms = NULL;

}


int search(char *txt, char *pat)
{
    int n = strlen(txt);
    int m = strlen(pat);
    int bc[NO_OF_CHARS];
    GetBcTable(pat, bc);
    int *gs = (int *)malloc(sizeof(int) * m);
    GetGsTable(pat, gs);

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && txt[s + j] == pat[j]) {
            j--;
        }
        if (j < 0) {
            // s += (s + m < n) ? (m - bc[txt[s + m]] : 1); // 针对坏字符规则
            // s += gs[0]; // 针对好后缀规则
            return s;
        } else {
            s += maxCmp(j - bc[txt[s + j]], gs[j]);
        }
    }
}