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

vector<pii> inputs;

void solve() {
    int n, m;
    cin >> n >> m;

    inputs.clear();

    for (int i = 0, r, c; i < m; i++) {
        cin >> r >> c;
        inputs.pb({c, r});
    }

    sort(inputs.begin(), inputs.end());

    vector<map<int, int> > aa;
    map<int, int> _;
    aa.push_back(_);
    for (int i = 0, r, c; i < m; i++) {
        tie(c, r) = inputs[i];
        if (aa.back().count(c)) {
            aa.back().erase(c);
            map<int, int> _;
            aa.push_back(_);
        }
        else
            aa.back()[c] = r;
    }

    cerr << "sz " << aa.size() << '\n';

    for (auto &a : aa) {
        vector<pii> v(a.begin(), a.end());

        if (v.size() % 2) {
            cout << "NO\n";
            return;
        }
        else {
            for (int i = 0; i+1 < v.size(); i += 2) {
                int x = v[i].se;
                int y = v[i+1].se;
                int d = v[i+1].fi - v[i].fi;

                if (x == y) {
                    if (d % 2 == 0) {
                        cout << "NO\n";
                        return;
                    }
                }
                else {
                    if (d % 2 == 1) {
                        cout << "NO\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "YES\n";
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