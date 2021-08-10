// 给定一个整数，我们定义如下公式 ：
// N=a[1] + a[2] + a[3]+...+a[m]
// a[i]>0, 1<=m<=n
// 对于一个正整数，求解满足上面公式的所有版式组合，如对于整数4
// 4=4
// 4=3+1
// 4=2+1+1
// 4=1+1+1+1

int main()
{
    int m, n;
    int dp[200][200] = {0};
    while (scanf(("%d", &n) != EOF)) {
        m = n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) {
                    dp[i][j] = 1;
                } else if (i <= j) {
                    dp[i][j] = dp[i][i - 1] + 1;
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - j][j];
                }
            }
        }
    }
}