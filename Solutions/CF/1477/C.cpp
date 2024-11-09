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

int n;

void solve() {
    cin >> n;
    map<long long, int> m;
    for (int i = 0; i < 2*n; i++) {
        long long x; cin >> x;
        m[x]++;
    }

    vector<long long> v;

    for (auto op : m) {
        if (op.se != 2) {
            cout << "NO\n";
            return;
        }
        v.pb(op.fi);
    }

    long long acc = 0;
    long long prev = 0x3f3f3f3f3f3f3f3f;

    for (int i = n; i >= 1; i--) {
        long long d = v.back(); v.pop_back();
        if ((d-acc) <= 0 || (d-acc) % i != 0 || ((d-acc) / i) % 2 != 0 || (d-acc)/i >= prev) {
            cout << "NO\n";
            return;
        }
//        cerr << (d-acc)/i << '\n';
        prev = (d-acc)/i;
        acc += (d-acc) / i;
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