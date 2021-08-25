把字符串 s 看作是“abcdefghijklmnopqrstuvwxyz”的无限环绕字符串，所以 s 看起来是这样的："...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....". 

现在我们有了另一个字符串 p 。你需要的是找出 s 中有多少个唯一的 p 的非空子串，尤其是当你的输入是字符串 p ，你需要输出字符串 s 中 p 的不同的非空子串的数目。 

注意: p 仅由小写的英文字母组成，p 的大小可能超过 10000。

 

示例 1:

输入: "a"
输出: 1
解释: 字符串 S 中只有一个"a"子字符。
 

示例 2:

输入: "cac"
输出: 2
解释: 字符串 S 中的字符串“cac”只有两个子串“a”、“c”。.
 

示例 3:

输入: "zab"
输出: 6
解释: 在字符串 S 中有六个子串“z”、“a”、“b”、“za”、“ab”、“zab”。.

// my way:
int findSubstringInWraproundString(char * p){
    int n = strlen(p);
    int **dp = (int **)malloc(sizeof(int *) * 26);
    for (int i = 0; i < 26; i++) {
        dp[i] = (int *)malloc(sizeof(int) * n);
        memset(dp[i], 0, sizeof(int) * n);
    }
    int cnt = 1;
    dp[p[n - 1] - 97][0] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if(dp[p[i] - 97][0] == 0) {
            dp[p[i] - 97][0] = 1;
            cnt++;
        }
        for (int j = i + 1; j < n; j++) {
            if ((p[j - 1] + 1 - 97) % 26 != p[j] - 97) {
                break;
            } else if (dp[p[i] - 97][j - i] >= 1){
                continue;
            } else {
                dp[p[i] - 97][j - i]++;
                cnt++;
            }
        }
    }
    return cnt;
}


// other guys
#define LEN 26
int findSubstringInWraproundString(char *p)
{
    int len = strlen(p);
    int hash[LEN];
    memset(hash, 0, sizeof(hash));
    int res = 0;
    int *dp = (int *)malloc(sizeof(int) * len);
    memset(dp, 0, sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        if (i > 0 && (p[i] - p[i - 1] + LEN) % LEN == 1) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 1;
        }
        int ch = p[i] - 'a';
        hash[ch] = fmax(hash[ch], dp[i]);
    }
    for (int i = 0; i < LEN; i++) {
        res += hash[i];
    }
    return res;
}