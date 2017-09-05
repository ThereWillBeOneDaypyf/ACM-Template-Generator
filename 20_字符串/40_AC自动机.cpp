struct Trie
{
    int ch[maxnode][sigema_size];
    int val[maxnode];
    int f[maxnode];
    int sz;                                         //  结点总数
    Trie()
    {
        sz = 1;    //  初始时只有一个根结点
        clr (ch[0], 0, sizeof(ch[0]));
    }
    int idx(char c)
    {
        return c - 'a';    //  字符c的编号
    }
    //  插入字符串s，附加信息为v。注意v必须非0，因为0代表“本结点不是单词结点”
    void insert(char *s, int v)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (!ch[u][c])                          //  结点不存在
            {
                clr(ch[sz], 0);
                val[sz] = 0;                        //  中间结点的附加信息为0
                ch[u][c] = sz++;                    //  新建结点
            }
            u = ch[u][c];                           //  往下走
        }
        val[u] = v;                                 //  字符串最后一个字符的附加信息为v
    }
    //  查找字符串s，返回其附加信息
    int find(const char *s)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (!ch[u][c])
                return -1;
            u = ch[u][c];
        }
        return val[u];
    }
    //  删除字符串s
    void del(const char *s)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (!ch[u][c])
                return;
            u = ch[u][c];
        }
        val[u] = 0;
    }
    int getFail()
    {
        queue<int> q;
        f[0] = 0;
        //  初始化队列
        for (int c = 0; c < sigma_size; c++)
        {
            int u = ch[0][c];
            if (u)
            {
                f[u] = 0;
                q.push(u);
                last[u] = 0;
            }
        }
        //  按BFS顺序计算失配函数
        while (!q.empty())
        {
            int r = q.front();
            q.pop();
            for (int c = 0; c < sigma_size; c++)
            {
                int u = ch[r][c];
                if (!u) continue;
                q.push(u);
                int v = f[r];
                while (v && !ch[v][c]) v = f[v];
                f[u] = ch[v][c];
                last[u] = val[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
    //  在文本串T中找模版
    void find(char *T)
    {
        int n = strlen(T);
        int j = 0;                                  //  当前结点编号，初始为根结点
        for (int i = 0; i < n; i++)                 //  文本串当前指针
        {
            int c = idx(T[i]);
            while (j && !ch[j][c]) j = f[j];        //  顺着失配边走，直到可以匹配
            j = ch[j][c];
            if (val[j]) print(i, j);
            else if (last[j]) print(i, last[j])     //  找到了
            }
    }
    //  递归打印以结点j结尾的所有字符串
    void print(int j)
    {
        if (j)
        {
            printf("%d: %d\n", j, val[j]);
            print(last[j]);
        }
    }
};
