//Tarjan离线算法求LCA
const int maxn = "Edit";
int par[maxn];                      //并查集
int ans[maxn];                      //存储答案
vector<int> G[maxn];                //邻接表
vector<int> query[maxn], num[maxn]; //存储查询信息
bool vis[maxn];                     //是否被遍历
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        G[i].clear();
        query[i].clear();
        num[i].clear();
        par[i] = i;
        vis[i] = 0;
    }
}
void add_edge(int u, int v)
{
    G[u].pb(v);
}
void add_query(int id, int u, int v)
{
    query[u].pb(v);
    query[v].pb(u);
    num[u].pb(id);
    num[v].pb(id);
}
void tarjan(int u)
{
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (vis[v]) continue;
        tarjan(v);
        unite(u, v);
    }
    for (int i = 0; i < query[u].size(); i++)
    {
        int v = query[u][i];
        if (!vis[v]) continue;
        ans[num[u][i]] = find(v);
    }
}
