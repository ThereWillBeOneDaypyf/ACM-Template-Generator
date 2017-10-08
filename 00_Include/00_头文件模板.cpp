#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
// ---
// vim配置
// ---
syntax on
set cindent
set nu
set tabstop = 4
set shiftwidth = 4
set background = dark
map<C-A> ggVG"+y
map<F5>: call Run()<CR>
func !Run()
    exec "w"
    exec "!g++ -Wall % -o %<"
    exec "!./%<"
endfunc
