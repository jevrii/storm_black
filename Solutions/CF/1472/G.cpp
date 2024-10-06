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

int d[MAXN];
bool vis[MAXN];
int n, m;
vector<int> e[MAXN];
int d1[MAXN], ans[MAXN];

int dfs1(int v) {
//    cerr << "dfs1 " << v << '\n';
    int rx = d[v];
    vis[v] = 1;
    for (int u : e[v]) {
        if (not vis[u] && d[u] > d[v]) {
            int cur = dfs1(u);
            rx = min(cur, rx);
        }
    }
    return d1[v] = rx;
}

int dfs2(int v) {
    int rx = d1[v];
    vis[v] = 1;
    for (int u : e[v]) {
        if (d[u] > d[v]) {
            if (not vis[u]) {
                dfs2(u);
            }
            rx = min(rx, ans[u]);
        }

//        cerr << "node " << v << ' ' << "skip " << u << ' ' << d1[u] << '\n';
        rx = min(rx, d1[u]);
    }
    return ans[v] = rx;
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        e[i].clear();
        vis[i] = 0;
        d[i] = INF;
    }

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        e[u].pb(v);
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    d[1] = 0;

    while (q.size()) {
        int t = q.front(); q.pop();
        for (int u : e[t]) {
            if (not vis[u]) {
                vis[u] = 1;
                d[u] = d[t]+1;
                q.push(u);
            }
        }
    }

//    for (int i = 1; i <= n; i++)
//        cerr << d[i] << ' ';
//    cerr << '\n';

    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        d1[i] = ans[i] = d[i];
    }
    dfs1(1);

//    for (int i = 1; i <= n; i++)
//        cerr << d1[i] << ' ';
//    cerr << '\n';

    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    dfs2(1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i==n];
//        assert(ans[i] >= d[i]-1);
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