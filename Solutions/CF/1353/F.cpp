#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 2000006
#define MOD 998244353LL

int n, m;
long long a[105][105];
map<long long, long long> dp[105][105];

long long dpf(int x, int y, long long st) {
    if (dp[x][y].count(st)) return dp[x][y][st];

//    cerr << "cur " << x << ' ' << y << ' ' << st << '\n';

    int move = x-1+y-1;
    long long need_st = a[x][y] - move;

    if (need_st > st) {
        if (x == n and y == m)
            return need_st-st;
//        cerr << "keep st at " << st << " lower cur to " << a[x][y] - (need_st-st) << ", " << "cost " << need_st-st << '\n';
        long long ret = LLONG_MAX;
        if (x+1 <= n) ret = min(ret, dpf(x+1, y, st));
        if (y+1 <= m) ret = min(ret, dpf(x, y+1, st));
        return dp[x][y][st] = need_st-st + ret;
    }
    else {
        if (x == n and y == m)
            return (st-need_st)*(move);
//        cerr << "lower st to " << need_st << " keep cur at " << a[x][y] << ", " << "cost " << (st-need_st)*(move) << '\n';
        long long ret = LLONG_MAX;
        if (x+1 <= n) ret = min(ret, dpf(x+1, y, need_st));
        if (y+1 <= m) ret = min(ret, dpf(x, y+1, need_st));
        return dp[x][y][st] = (st-need_st)*(move) + ret;
    }
}

void solve() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            dp[i][j].clear();
        }


    cout << dpf(1, 1, a[1][1]) << '\n';

}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    auto start_time = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}