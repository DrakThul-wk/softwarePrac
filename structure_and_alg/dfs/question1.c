给你一个大小为 m x n 的网格和一个球。球的起始坐标为 [startRow, startColumn] 。你可以将球移到在四个方向上相邻的单元格内（可以穿过网格边界到达网格之外）。你 最多 可以移动 maxMove 次球。

给你五个整数 m、n、maxMove、startRow 以及 startColumn ，找出并返回可以将球移出边界的路径数量。因为答案可能非常大，返回对 109 + 7 取余 后的结果。


#define MAXSLIMIT 1000000007
#define MAXS 52
int record[MAXS][MAXS][MAXS];
int row;
int col;
int dfs(int x, int y, int k)
{
    if (x < 0 || x >= row || y < 0 || y >= col) {
        return 1;
    }
    if (k == 0) {
        return 0;
    }
    if (record[x][y][k] != -1) {
        return record[x][y][k]; // 关键代码在这里，具有记忆特性，找过的直接返回，回忆速度！
    }
    int ans = 0;
    int dirs[4][2] = {{-1,0}, {1,0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; i++) {
        ans += dfs(x + dirs[i][0], y + dirs[i][1], k - 1);
        ans = ans % MAXSLIMIT;
    }
    record[x][y][k] = ans;
    return ans;
}
int findPaths(int m, int n, int maxMove, int startRow, int startColumn){
    memset(record, -1, sizeof(record));
    row = m;
    col = n;
    int ret = dfs(startRow, startColumn, maxMove);
    return ret;
}