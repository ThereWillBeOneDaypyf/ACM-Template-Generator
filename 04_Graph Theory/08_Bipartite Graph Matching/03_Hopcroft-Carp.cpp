/*
邻接表存图,vector实现
vector先初始化,然后加边
复杂度O(sqrt(n)*E)
uN 为左端的顶点数,使用前赋值(点编号0开始)
*/
const int maxn = "Edit";
vector<int> G[maxn];
int uN;
int Mx[maxn], My[maxn];
int dx[maxn], dy[maxn];
int dis;
bool used[maxn];
inline void init(int n)
{
    for (int i = 0; i < n; i++) G[i].clear();
}
inline void addedge(int u, int v) { G[u].pb(v); }
bool SearchP()
{
    queue<int> Q;
    dis = INF;
    clr(dx, -1);
    clr(dy, -1);
    for (int i = 0; i < uN; i++)
        if (Mx[i] == -1)
        {
            Q.push(i);
            dx[i] = 0;
        }
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if (dx[u] > dis) break;
        int sz = G[u].size();
        for (int i = 0; i < sz; i++)
        {
            int v = G[u][i];
            if (dy[v] == -1)
            {
                dy[v] = dx[u] + 1;
                if (My[v] == -1)
                    dis = dy[v];
                else
                {
                    dx[My[v]] = dy[v] + 1;
                    Q.push(My[v]);
                }
            }
        }
    }
    return dis != INF;
}
bool DFS(int u)
{
    int sz = G[u].size();
    for (int i = 0; i < sz; i++)
    {
        int v = G[u][i];
        if (!used[v] && dy[v] == dx[u] + 1)
        {
            used[v] = true;
            if (My[v] != -1 && dy[v] == dis) continue;
            if (My[v] == -1 || DFS(My[v]))
            {
                My[v] = u, Mx[u] = v;
                return true;
            }
        }
    }
    return false;
}
int MaxMatch()
{
    int res = 0;
    clr(Mx, -1), clr(My, -1);
    while (SearchP())
    {
        clr(used, false);
        for (int i = 0; i < uN; i++)
            if (Mx[i] == -1 && DFS(i)) res++;
    }
    return res;
}
