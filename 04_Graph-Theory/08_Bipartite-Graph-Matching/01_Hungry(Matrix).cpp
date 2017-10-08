/*
二分图匹配(匈牙利算法的DFS实现)(邻接矩阵形式)
初始化:g[][]两边顶点的划分情况
建立g[i][j]表示i->j的有向边就可以了,是左边向右边的匹配
g没有边相连则初始化为0
uN是匹配左边的顶点数,vN是匹配右边的顶点数
调用:res=hungary();输出最大匹配数
优点:适用于稠密图,DFS找增广路,实现简洁易于理解
时间复杂度:O(VE)
顶点编号从0开始的
*/
const int maxn = "Edit";
int uN, vN;        //u,v的数目,使用前面必须赋值
int g[maxn][maxn]; //邻接矩阵
int linker[maxn];
bool used[maxn];
bool dfs(int u)
{
    for (int v = 0; v < vN; v++)
        if (g[u][v] && !used[v])
        {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    return false;
}
int hungary()
{
    int res = 0;
    clr(linker, -1);
    for (int u = 0; u < uN; u++)
    {
        clr(used, 0);
        if (dfs(u)) res++;
    }
    return res;
}
