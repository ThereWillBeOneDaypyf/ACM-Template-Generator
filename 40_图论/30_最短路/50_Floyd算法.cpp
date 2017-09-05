// ---
// $O(n^3)$求出任意两点间最短路
// ---
const int MAXN = "Edit";
const int INF = 0x3f3f3f3f;
int G[MAXN][MAXN];
void init(int n)
{
    clr(G, 0x3f);
    for (int i = 0; i < n; i++)
        G[i][i] = 0;
}
void add_edge(int u, int v, int w)
{
    G[u][v] = min(G[u][v], w);
}
void Floyd(int n)
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}
