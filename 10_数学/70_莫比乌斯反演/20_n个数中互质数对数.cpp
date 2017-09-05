//  有n个数（n<=100000），问这n个数中互质的数的对数
clr(b, 0);
_max = 0;
ans = 0;
for (int i = 0; i < n; i++)
{
    scanf("%d", &x);
    if (x > _max) _max = x;
    b[x]++;
}
int cnt;
for (int i = 1; i <= _max; i++)
{
    cnt = 0;
    for (long long j = i; j <= _max; j += i)
        cnt += b[j];
    ans += 1LL * mu[i] * cnt * cnt;
}
printf("%lld\n", (ans - b[1]) / 2);
