// 返回y中x的个数
int next[10010];
void kmp_pre(char x[], int m, int next[]) {
    int i, j; j = next[0] = -1; i = 0;
    while (i < m) {
        while (j != -1 && x[i] != x[j])
            j = next[j];
        next[++i] = ++j;
    }
}
int KMP (char x[], int m, char y[], int n) {
    int i, j, ans; i = j = ans = 0;
    kmp_pre (x, m, next);
    while (i < n) {
        while (j != -1 && y[i] != x[j]) j = next[j];
        i++; j++;
        if (j >= m) {
            ans++; j = next[j];
        }
    }
    return ans;
}
