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

#define MAXN 1000006
#define INF 0x3f3f3f3f
//#define MOD 998244353LL
#define MOD 1000000007LL
// Returns minimum x for which a ^ x % m = b % m.]



void solve() {
    long long x, y;
    cin >> x >> y;

    vector<int> a, b, c, d;

    string s, t;
    for (int i = 0; i < 64; i++) {
        if (i % 2) {
            if (x % 2)
                a.pb(i/2);
            if (y % 2)
                b.pb(i/2);
        }
        else {
            if (x % 2)
                c.pb(i/2);
            if (y % 2)
                d.pb(i/2);
        }
        x /= 2;
        y /= 2;
    }

    if (a.size() != b.size()) {
        cout << -1 << '\n';
        return;
    }
    if (c.size() != d.size()) {
        cout << -1 << '\n';
        return;
    }

    int ans = 0;

    for (int i = 0; i < a.size(); i++) {
        ans += abs(a[i] - b[i]);
    }

    for (int i = 0; i < c.size(); i++) {
        ans += abs(c[i] - d[i]);
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
        cout << "Case " << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}