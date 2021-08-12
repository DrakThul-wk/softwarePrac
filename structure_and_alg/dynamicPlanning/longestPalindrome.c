// 给你一个字符串 s，找到 s 中最长的回文子串。

//  

// 示例 1：

// 输入：s = "babad"
// 输出："bab"
// 解释："aba" 同样是符合题意的答案。
// 示例 2：

// 输入：s = "cbbd"
// 输出："bb"
// 示例 3：

// 输入：s = "a"
// 输出："a"
// 示例 4：

// 输入：s = "ac"
// 输出："a"
//  

// 提示：

// 1 <= s.length <= 1000
// s 仅由数字和英文字母（大写和/或小写）组成

分析：
dp[i][j]代表i到j是否为最长回文子串
dp[5][5] = s[5] == s[5]
dp[4][4] = s[4] == s[4]
dp[3][5] = dp[4][4] && s[3] == s[5]

#define MAXS 1000
char * longestPalindrome(char * s)
{
    int dp[MAXS][MAXS] = {0};
    int maxValue, maxI, maxJ;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j< n; j++) {
            int len = j - i;
            if (len <= 1) {
                dp[i][j] = (s[i] == s[j]);
            } else {
                if (dp[i + 1][j - 1] == 1 && s[i] == s[j]) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            }
            if (dp[i][j] == 1 && maxValue < j - i) {
                maxValue = j - i + 1;
                maxI = i;
                maxJ = j;
            }
        }
    }
    char *ret = (char *)malloc(sizeof(char) * (maxValue + 1));
    memcpy(ret, &s[maxI], sizeof(char) * maxValue);
    ret[maxValue] = '\0';
    return ret;
}