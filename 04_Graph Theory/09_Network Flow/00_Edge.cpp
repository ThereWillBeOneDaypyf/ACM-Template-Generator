// 以下算法除特殊说明外均使用如下数据结构表示一条弧
struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
