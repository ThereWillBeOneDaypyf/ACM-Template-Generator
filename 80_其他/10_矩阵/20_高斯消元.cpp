void gauss()
{
    int now = 1, to;
    double t;
    for (int i = 1; i <= n; i++) {
        /*for (to = now; !a[to][i] && to <= n; to++);
        //做除法时减小误差，可不写
        if (to != now)
            for (int j = 1; j <= n + 1; j++)
                swap(a[to][j], a[now][j]);*/
        t = a[now][i];
        for (int j = 1; j <= n + 1; j++)
            a[now][j] /= t;
        for (int j = 1; j <= n; j++)
            if (j != now) {
                t = a[j][i];
                for (int k = 1; k <= n + 1; k++)
                    a[j][k] -= t * a[now][k];
            }
        now++;
    }
}

// ---
// 求线性基
// ---
for (int i = 1; i <= m; i++)
    for (int j = 63; ~j; j--)
        if ((a[i] >> j) & 1) {
            if (!ins[j])
            {
                ins[j] = a[i];
                break;
            }
            else
                a[i] ^= ins[j];
        }
