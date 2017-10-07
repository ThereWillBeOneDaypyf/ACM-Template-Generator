#define Lson l, m, dep + 1
#define Rson m + 1, r, dep + 1

int tree[20][maxn];   //表示每层每个位置的值
int sorted[maxn];     //已经排序好的数
int toleft[20][maxn]; //toleft[p][i]表示第i层从1到i有数分入左边

void build(int l, int r, int dep)
{
    if (l == r) return;
    int m = (l + r) >> 1, same = m - l + 1; //表示等于中间值而且被分入左边的个数
    for (int i = l; i <= r; i++)
        if (tree[dep][i] < sorted[m])
            same--;
    int lpos = l;
    int rpos = m + 1;
    for (int i = l; i <= r; i++)
    {
        if (tree[dep][i] < sorted[m])
            tree[dep + 1][lpos++] = tree[dep][i];
        else if (tree[dep][i] == sorted[m] && same > 0)
        {
            tree[dep + 1][lpos++] = tree[dep][i];
            same--;
        }
        else
            tree[dep + 1][rpos++] = tree[dep][i];
        toleft[dep][i] = toleft[dep][l - 1] + lpos - l;
    }
    build(Lson);
    build(Rson);
}
//查询区间第k小的数
int query(int L, int R, int k, int l, int r, int dep)
{
    if (L == R) return tree[dep][L];
    int m = (l + r) >> 1;
    int cnt = toleft[dep][R] - toleft[dep][L - 1];
    if (cnt >= k)
    {
        int newl = l + toleft[dep][L - 1] - toleft[dep][l - 1];
        int newr = newl + cnt - 1;
        return query(newl, newr, k, Lson);
    }
    else
    {
        int newr = R + toleft[dep][r] - toleft[dep][R];
        int newl = newr - (R - L - cnt);
        return query(newl, newr, k - cnt, Rson);
    }
}
