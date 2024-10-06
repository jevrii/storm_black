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

int n, a[MAXN], dp[MAXN];
stack<pii> s1, s2;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    s1.push(mp(a[0], 0));
    s2.push(mp(a[0], 0));
    for (int i = 1; i < n; i++) {
        bool come_same = 0;
        while (s1.size()) {
            if (not come_same) {
                dp[i] = min(dp[i], dp[s1.top().se]+1);
//                cerr << "minify " << i << ' ' << s1.top().se << ' ' << dp[i] << '\n';
            }
            if (s1.top().fi == a[i])
                come_same = 1;
            if (s1.top().fi >= a[i])
                s1.pop();
            else break;
        }
        s1.push(mp(a[i], i));

        come_same = 0;
        while (s2.size()) {
            if (not come_same) {
                dp[i] = min(dp[i], dp[s2.top().se]+1);
//                cerr << "minify " << i << ' ' << s2.top().se << ' ' << dp[i] << '\n';
            }
            if (s2.top().fi == a[i])
                come_same = 1;
            if (s2.top().fi <= a[i])
                s2.pop();
            else break;
        }
        s2.push(mp(a[i], i));
    }

    cout << dp[n-1] << '\n';

}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    auto start_time = clock();
#endif
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}