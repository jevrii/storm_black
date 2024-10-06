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
#define MAXN 2010
#define MOD 998244353LL

int match[MAXN], vis[MAXN]; // match[]: the partner of that node
vector<int> e[MAXN];

bool dfs(int v){
    if (vis[v]) return 0; vis[v]=1;
    for (int u : e[v]){
        if (match[u] == -1 || dfs(match[u])){
            match[v] = u, match[u] = v;
            return 1;
        }
    }
    return 0;
}

int MCBM(int N){ // vertices should be numbered from 0 to N-1, undirected edges
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < N; i++)
        if (match[i] == -1) {
            fill(vis, vis+N, 0);
            ans += dfs(i);
        }
    return ans;
}

void solve() {
    int m; cin >> m;
    map<string, int> to_id;
    for (int i = 0; i < 2*m+5; i++)
        e[i].clear();
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        a += "*";
        b += "#";
        int u, v;
        if (to_id.count(a)) u = to_id[a];
        else u = to_id.size(), to_id[a] = u;

        if (to_id.count(b)) v = to_id[b];
        else v = to_id.size(), to_id[b] = v;

        e[u].pb(v);
        e[v].pb(u);
    }

    int mx = MCBM(to_id.size());
    for (int i = 0; i < to_id.size(); i++)
        if (match[i] == -1) mx++;
    cout << m-mx << '\n';
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