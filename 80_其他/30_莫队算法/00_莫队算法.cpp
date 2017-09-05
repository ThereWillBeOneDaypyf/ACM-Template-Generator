// ---
// 莫队算法,可以解决一类静态,离线区间查询问题。分成 $\sqrt{x}$ 块,分块排序。
// ---
struct query
{
    int L, R, id;
} node[maxn];
bool cmp(query a, query b)
{
    if (a.L / unit != b.L / unit)
        return a.L / unit < b.L / unit;
    else
        return a.R < b.R;
}
void solve()
{
    tmp = 0;
    clr(num, 0);
    clr(ans, 0);
    int L = 1;
    int R = 0;
    for (int i = 0; i < m; i++)
    {
        while (node[i].L < L) add(a[--L]);
        while (node[i].L > L) del(a[L++]);
        while (node[i].R < R) del(a[R--]);
        while (node[i].R > R) add(a[++R]);
        ans[node[i].id] = tmp;
    }
}
