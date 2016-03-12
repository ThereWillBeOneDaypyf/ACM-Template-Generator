// ---
// $O(\log n)$查询和修改数组的前缀和
// ---
// 注意下标应从1开始
#define lowbit(i) (i&(-i))
int bit[maxn], n; 
int query(int i){
	int s = 0;
	while(i){
		s += bit[i];
		i -= lowbit(i);
	}
	return s;
}
void add(int i, int x){
	while(i<=n){
		bit[i] += x;
		i += lowbit(i);
	}
}
