// ---
// $n$个人围成一圈，从第一个开始报数，第$m$个将被杀掉
// ---
int n, m, r = 0;
for (int k = 1; k <= n; ++k) r = (r + m) % k;
cout << r + 1 << endl;
