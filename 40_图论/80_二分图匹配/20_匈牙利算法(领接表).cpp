/*
匈牙利算法邻接表形式
使用前用init()进行初始化
加边使用函数addedge(u,v)
*/

const int maxn = "Edit";
int n;
vector<int> G[maxn];
int linker[maxn];
bool used[maxn];
void init(int n)
{
    for (int i = 0; i < n; i++)
        G[i].clear();
}
void addedge(int u, int v)
{
    G[u].pb(v);
}
bool dfs(int u)
{
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (!used[v])
        {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int ans = 0;
    clr(linker, -1);
    for (int u = 0; u < n; v++)
    {
        clr(vis, 0);
        if (dfs(u)) ans++;
    }
    return ans;
}
