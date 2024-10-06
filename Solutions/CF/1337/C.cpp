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

int n, k;
vector<int> e[MAXN];
int sz[MAXN], deg[MAXN], par[MAXN], dep[MAXN];

void dfs(int v, int p = -1, int d = 0) {
    sz[v] = 1;
    for (int u : e[v]) {
        if (u-p) {
            dfs(u, v, d+1);
            sz[v] += sz[u];
        }
    }
    dep[v] = d;
    par[v] = p;
}


void solve() {
    cin >> n >> k;
    for (int i = 0, u, v; i < n-1; i++) {
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
        deg[u]++;
        deg[v]++;
    }

    dfs(1);

    priority_queue<pii> q;

    for (int i = 2; i <= n; i++) {
        if (deg[i] == 1) {
            q.push(mp(dep[i]-sz[i], i));
        }
    }

    long long ans = 0;

    for (int iter = 0; iter < k; iter++) {
        int v = q.top().se; q.pop();
        deg[par[v]]--;
        ans += dep[v]-sz[v]+1;
        if (deg[par[v]] == 1) {
            q.push(mp(dep[par[v]]-sz[par[v]], par[v]));
        }
    }

    cout << ans << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    auto start_time = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

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