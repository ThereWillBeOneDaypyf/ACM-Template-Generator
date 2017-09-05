// ---
// 若一些数据本身很大，无法作为下标储存，且数据的作用只和其相对大小有关时，可以将数据进行离散化。
// ---
// B为A的副本。
sort(B, B + n);
int size = unqiue(B, B + n) - B; // size为离散化后元素的个数。
for (int i = 0; i < n; i++)
    A[i] = lower_bound(B, B + size, A[i]) - B + 1; // 离散化
