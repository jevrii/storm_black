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

void solve() {
    int n;
    cin >> n;
    vector<pii> ans;

    if (n > 8) {
        for (int i = 9; i <= n-1; i++)
            ans.pb({i, n});
        int x = n;
        while (x > 1){
            ans.pb({n, 8});
            x = (x+7)/8;
        }
        for (int i = 3; i <= 7; i++) {
            ans.pb({i, 8});
        }
        for (int i = 0; i < 3; i++) {
            ans.pb({8, 2});
        }
    }
    else {
        for (int i = 3; i < n; i++)
            ans.pb({i, n});
        int x = n;
        while (x > 1) {
            ans.pb({n, 2});
            x = (x + 1) / 2;
        }
    }
    cout << ans.size() << '\n';

    for (auto op : ans)
        cout << op.fi << ' ' << op.se << '\n';


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