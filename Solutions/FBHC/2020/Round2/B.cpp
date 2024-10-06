#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize ("trapv")
using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 1000006
//#define MOD 998244353LL
#define MOD 1000000007LL

int n;
long double p;

long double dp[8005][8005];

long double f(int x) {
    return x*(x-1)/2;
}

long double dpf(int x, int y) {
    if (x == -1 || y == -1) return 0;
    if (x+1+y == 1) return 0;
    if (dp[x][y] != -1) return dp[x][y];
    int tot = x+1+y;
    return dp[x][y] = 1 + dpf(x, y-1)*f(y)/f(tot) + dpf(x-1, y)*f(x)/f(tot) +
                      p * dpf(x-1, y) * x*y/f(tot) + (1-p) * dpf(x, y-1) * x*y/f(tot) +
                      p * dpf(x-1, y) * x/f(tot) + (1-p) * dpf(x, y-1) * y/f(tot);
}

void solve() {
    cin >> n >> p;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = -1;
    cout << '\n';
    for (int i = 1; i <= n; i++)
        cout << fixed << setprecision(12) << dpf(i-1, n-i) << '\n';
}

int main() {
#ifdef LOCAL
//    freopen("capastaty_input.txt", "r", stdin);
//    freopen("capastaty_validation_input.txt", "r", stdin);
//    freopen("input.txt", "r", stdin);
    freopen("elimination_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start_time = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for (int no = 1; no <= t; no++) {
        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}