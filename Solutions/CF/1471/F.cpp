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

#define MAXN 300005
#define INF 0x3f3f3f3f3f3f3f3f
//#define MOD 998244353LL
#define MOD 1000000007LL

vector<int> e[MAXN];
int p[MAXN];
int ord[MAXN];
int vis[MAXN];
int n, m;
bool choose[MAXN];

int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
}

void join(int x, int y) {
    x = get(x);
    y = get(y);
    p[x] = y;
}

void dfs(int v) {
    vis[v] = 1;
    bool ok = 1;
    for (int u : e[v]) {
        if (choose[u]) {
            ok = 0;
            break;
        }
    }
    if (ok)
        choose[v] = 1;
    for (int u : e[v]) {
        if (not vis[u])
            dfs(u);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        ord[i] = i;
        vis[i] = 0;
        choose[i] = 0;
        e[i].clear();
    }
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs(1);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (choose[i]) {
            ans.pb(i);
            for (int u : e[i])
                join(u, i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (get(i) != get(1)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i+1==ans.size()];
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