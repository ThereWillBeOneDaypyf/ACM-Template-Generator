// ---
// 利用exgcd求$a$在模$m$下的逆元，需要保证$gcd(a, m) == 1$.
// ---
ll inv(ll a, ll m)
{
    ll x, y;
    ll d = exgcd(a, m, x, y);
    return d == 1 ? (x + m) % m : -1;
}
// ---
// $a < m$ 且 $m$为素数时，有以下两种求法
// ---
ll inv(ll a, ll m) { return a == 1 ? 1 : inv(m % a, m) * (m - m / a) % m; }
ll inv(ll a, ll m) { return Pow(a, m - 2, m); }
