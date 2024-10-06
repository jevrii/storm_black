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
#define MAXN 300005
//#define MOD 998244353LL
#define MOD 1000000007LL

vector<int> centroids;
vector<int> e[MAXN];
int n, leaf;
int com[MAXN];

int dfs(int v, int p=-1) {
    int sz = 1;
    int mx = 0;
    for (int u : e[v]) {
        if (u-p) {
            int sub = dfs(u, v);
            mx = max(sub, mx);
            sz += sub;
        }
    }
    mx = max(mx, n-sz);
    com[v] = mx;
//    cerr << v << ' ' << p << ' ' << mx << ' ' << sz << '\n';
    return sz;
}

void dfs2(int v, int p = -1) {
//    cerr << "dfs2" << '\n';
    if (e[v].size() == 1) {
        leaf = v;
        return;
    }
    for (int u : e[v]) {
        if (u-p and u != centroids[0]) {
            dfs2(u, v);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        e[i].clear();
    centroids.clear();
    for (int i = 0, u, v; i < n-1; i++) {
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs(1);
    int lo = *min_element(com+1, com+1+n);
    for (int i = 1; i <= n; i++)
        if (com[i] == lo) {
            centroids.pb(i);
        }

    if (centroids.size() == 1) { // cut any
//        cerr << "one\n";
        cout << 1 << ' ' << e[1][0] << '\n';
        cout << 1 << ' ' << e[1][0] << '\n';
    }
    else{
        dfs2(centroids[1]);
        cout << leaf << ' ' << e[leaf][0] << '\n';
        cout << centroids[0] << ' ' << leaf << '\n';
    };
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