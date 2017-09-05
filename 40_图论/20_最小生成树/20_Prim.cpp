// 耗费矩阵cost[][],标号从0开始,0~n-1
// 返回最小生成树的权值,返回-1表示原图不连通
const int INF = 0x3f3f3f3f;
const int MAXN = 110;
bool vis[MAXN];
int lowc[MAXN];
int Prim(int cost[][MAXN], int n)
{
    int ans = 0;
    clr(vis, 0);
    vis[0] = 1;
    for (int i = 1; i < n; i++)
        lowc[i] = cost[0][i];
    for (int i = 1; i < n; i++)
    {
        int minc = INF;
        int p = -1;
        for (int j = 0; j < n; j++)
            if (!vis[j] && minc > lowc[j])
            {
                minc = lowc[j];
                p = j;
            }
        if (minc == INF) return -1;
        vis[p] = 1;
        ans += minc;
        for (int j = 0; j < n; j++)
            if (!vis[j] && lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
    }
    return ans;
}
