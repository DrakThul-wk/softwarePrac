// bf 即为暴力匹配法，算法非常的简单
int bfAlg(char *txt, char *pat)
{
    int i, j;
    int n = strlen(txt);
    int m = strlen(pat);
    i = 0;
    j = 0;
    while (i < n && j < m) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == m) {
        return i - j;
    }
    return -1; // no match
}