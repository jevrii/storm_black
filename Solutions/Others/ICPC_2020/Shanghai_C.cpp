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

#define MAXN 200005
#define INF 0x3f3f3f3f3f3f3f3f
//#define MOD 998244353LL
#define MOD 1000000007LL

long long x, y;
long long dp[35][2][2];

long long dpf(int pos, bool lim_x, bool lim_y) {
    long long ret = 0;

    if (pos == -1)
        return 1;

    if (dp[pos][lim_x][lim_y] != -1) return dp[pos][lim_x][lim_y];

    bool bx = (1LL<<pos)-1 > x || (lim_x && ((x & (1LL<<pos)) == 0));
    bool by = (1LL<<pos)-1 > y || (lim_y && ((y & (1LL<<pos)) == 0));

//    cout << "cur " << pos << ' ' << lim_x << lim_y << '\n';

    if ((1LL << pos) <= x && ((!lim_x) || (x & (1LL << pos)))) { // can put 1 at x here
//        cout << "cur " << pos << ' ' << lim_x << lim_y << ' ' << " add1 x " << lim_x << ' ' << by << '\n';
        ret += dpf(pos-1, lim_x, by);
    }

    if ((1LL << pos) <= y && ((!lim_y) || (y & (1LL << pos)))) { // can put 1 at x here
//        cout << "cur " << pos << ' ' << lim_x << lim_y << ' ' << " add1 y " << bx << ' ' << lim_y << '\n';
        ret += dpf(pos-1, bx, lim_y);
    }

//    cout << "cur " << pos << ' ' << lim_x << lim_y << ' ' << " non " << bx << ' ' << by << '\n';
    ret += dpf(pos-1, bx, by);

//    cout << pos << ' ' << lim_x << ' ' << lim_y << ' ' << ret << '\n';

    return dp[pos][lim_x][lim_y] = ret % MOD;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> x >> y;

    long long ans = 0;

//    cout << dpf(10, 1, 1) << '\n';
//    int cnt = 0;
//    for (int i = 0; i <= x; i++) {
//        for (int j = (i == 0); j <= y; j++) {
//            if ((i & j) == 0)
//                cnt++;
//        }
//    }
//    cout << cnt << '\n';

    for (int p = 0; (1LL << p) <= x; p++) {
        ans += (p+1) * dpf(p-1, (1LL << (p+1))-1 > x, (1LL << (p))-1 > y);
        ans %= MOD;
    }

    for (int p = 0; (1LL << p) <= y; p++) {
        ans += (p+1) * dpf(p-1, (1LL << (p))-1 > x, (1LL << (p+1))-1 > y);
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
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