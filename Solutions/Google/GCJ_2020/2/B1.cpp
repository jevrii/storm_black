#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 200005
#define MOD 998244353LL

vector<pii> edges;
vector<int> e[105];
int x[105];
int cost[105][105];
int done[105];
int val[105];
int n, m;

void solve() {
    cin >> n >> m;
    edges.clear();
    memset(done, 0, sizeof(done));
    val[1] = 0;

    memset(cost, -1, sizeof(cost));

    for (int i = 2; i <= n; i++) {
        cin >> x[i];
        if (x[i] > 0) val[i] = x[i];
    }

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        edges.pb(mp(u, v));
        e[u].pb(v);
        e[v].pb(u);
    }

    done[1] = 1;

    for (int ord = 1, prev = 0; ord <= 100; ord++) {
        int mx = prev;
        for (int v = 1; v <= n; v++) {
            if (-x[v] == ord) {
                for (int u : e[v]) {
                    if (done[u]) {
//                        cerr << v << ' ' << "get " << u << '\n';
                        mx = max(mx, val[u]);
                    }
                }
            }
        }
        mx++;
        for (int v = 1; v <= n; v++) {
            if (-x[v] == ord) {
                for (int u : e[v]) {
                    if (done[u]) {
//                        cerr << v << ' ' << "setcost " << u << ' ' << mx-val[u] << '\n';
                        cost[u][v] = cost[v][u] = mx-val[u];
                    }
                }
            }
        }
        for (int v = 1; v <= n; v++) {
            if (-x[v] == ord) {
                done[v] = 1;
                val[v] = mx;
            }
        }
        prev = mx;
    }

    vector<int> good;

    for (int v = 1; v <= n; v++) {
        if (not done[v]) {
            int mx = 1e9;
            for (int u : e[v]) {
                if (done[u])
                    mx = min(mx, val[u]);
            }
            if (mx == 1e9) continue;
            else good.pb(v);
            for (int u : e[v]) {
                if (done[u])
                    cost[u][v] = cost[v][u] = mx-val[u];
            }
        }
    }

    for (int x : good) done[x] = 1;

    for (int v = 1; v <= n; v++) {
        for (int u = v+1; u <= n; u++) {
            if (not done[u] or not done[v]) {
                cost[u][v] = cost[v][u] = abs(val[u]-val[v]);
            }
        }
    }

    for (auto op: edges) {
        if (cost[op.fi][op.se] == -1) cost[op.fi][op.se] = 1e6;
        cout << cost[op.fi][op.se] << ' ';
    }
    cout << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    auto start_time = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for (int no = 1; no <= t; no++) {
        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}