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

int h[MAXN], w[MAXN];
map<int, vector<pii> > m;
int n;

void solve() {
    m.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> w[i];
        m[h[i]].pb(mp(w[i], i));
        m[w[i]].pb(mp(h[i], i));
    }

    vector<int> ans(n+1, -1);

    set<pii> got;

    for (auto &op : m) {
//        cerr << "at x " << op.fi << '\n';
        for (auto point : op.se) {
            int x, y;
            tie(x, y) = point;

            if (got.size()) {
                auto it = got.lower_bound(make_pair(x, -1));
                if (it != got.begin()) {
                    it--;
//                    cerr << "  get " << y << ' ' << (it -> se) << '\n';
                    ans[y] = it -> se;
                }
            }
        }

        for (auto point : op.se) {
//            cerr << "  insert y " << point.fi << ' ' << point.se << '\n';
            got.insert(point);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i==n];
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