输入一个字符串，打印出该字符串中字符的所有排列。

 

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 

限制：

1 <= s 的长度 <= 8

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MAXS 50000 //一般来讲要满足n!
 #define NO_OF_CHARS 9
 int visit[NO_OF_CHARS];
 void BackTrace(char **ret, char *s, int idx, int *returnSize, char *tmp)
 {
     if (idx == strlen(s)) {
        ret[*returnSize] = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        memcpy(ret[*returnSize], tmp, sizeof(char) * strlen(s));
        ret[*returnSize][idx] = '\0';
        (*returnSize)++;
        return;
     }
     for (int i = 0; i < strlen(s); i++) {
        // 这句为经典语句， 当visit[i - 1]没有被使用，说明在回溯过程中，就是前面的字符已经被应用了。需要特别注意！！
        if (visit[i] == 1 || (i >= 1 && visit[i - 1] == 0 && s[i] == s[i - 1])) { 
            continue;
        } else if (visit[i] == 0) {
            visit[i] = 1;
            tmp[idx] = s[i];
            BackTrace(ret, s, idx + 1, returnSize, tmp);
            visit[i] = 0;
        }
     }
 }
 int cmp(void *ele1, void *ele2)
 {
     char *p1 = (char *)ele1;
     char *p2 = (char *)ele2;
     return (*p1 - *p2);
 }
char** permutation(char* s, int* returnSize){
    char **ret = (char **)malloc(sizeof(char) * MAXS);
    memset(visit, 0, sizeof(visit));
    char *tmp = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    *returnSize = 0;
    qsort(s, strlen(s), sizeof(char), cmp); // 注意先排序，让相同的字符串连在一起
    BackTrace(ret, s, 0, returnSize, tmp);
    return ret;
}