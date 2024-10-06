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
long long a[MAXN], v[MAXN], ps[MAXN], k;

void solve() {
    cin >> n >> q >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        v[i] = a[i+1] - a[i-1] - 2;

    for (int i = 1; i <= n; i++)
        ps[i] = ps[i-1] + v[i-1];

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        if (l == r) {
            cout << k-1 << '\n';
            continue;
        }

        long long ans = 0;
        ans += a[l+1]-1-1;
        ans += k-a[r-1]-1;

        if (l+1 <= r-1)
            ans += ps[r]-ps[l+1];
//        for (int i = l+1; i < r; i++) {
//            cerr << a[i+1] << a[i-1] << '\n';
//            ans += a[i+1] - a[i-1] - 2;
//        }

        cout << ans << '\n';
    }

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