// 存图前记得初始化
// Ans排序结果，G邻接表，deg入度，map用于判断重边
// 排序成功返回1，存在环返回0
const int maxn = "Edit";
typedef pair<int, int> PII;
int Ans[maxn];
vector<int> G[maxn];
int deg[maxn];
map<PII, bool> S;
void init(int n)
{
    S.clear();
    for (int i = 0; i < n; i++) G[i].clear();
    clr(deg, 0);
    clr(Ans, 0);
}
void add_edge(int u, int v)
{
    if (S[mp(u, v)]) return;
    G[u].pb(v);
    S[mp(u, v)] = 1;
    deg[v]++;
}
bool Toposort(int n)
{
    int tot = 0;
    queue<int> que;
    for (int i = 0; i < n; ++i)
        if (deg[i] == 0) que.push(i);
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        Ans[tot++] = v;
        for (int i = 0; i < G[v].size(); ++i)
        {
            int t = G[v][i];
            if (--deg[t] == 0) que.push(t);
        }
    }
    if (tot < n) return false;
    return true;
}
