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

int n, q;
long long a[MAXN], ps[MAXN], pm[MAXN];

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    partial_sum(a, a+n, ps);
    pm[0] = ps[0];
    for (int i = 1; i < n; i++)
        pm[i] = max(pm[i-1], ps[i]);

    while (q--) {
        long long x;
        cin >> x;
        if (pm[n-1] < x && ps[n-1] <= 0) {
            cout << -1 << " \n"[q==0];
        }
        else {
            if (ps[n-1] <= 0) {
                auto it = lower_bound(pm, pm+n, x);
                cout << it-pm << " \n"[q==0];
            }
            else {
                long long buf = max(0LL, (x-pm[n-1]+ps[n-1]-1)/ps[n-1]);
//                cerr << buf << '\n';
                auto it = lower_bound(pm, pm+n, x-buf*ps[n-1]);
                cout << buf*n + (it-pm) << " \n"[q==0];
            }
        }
    }
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