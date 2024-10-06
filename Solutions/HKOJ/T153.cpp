#include <bits/stdc++.h>

#define pii pair<int, int>
#define pll pair<long long, long long>
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
#define MAXN 105
#define MOD 998244353LL

#define SHIFT 20000020

int n, c;
vector<pii> e[MAXN];
int ans[105][105];

vector<int> knapsack(vector<vector<int> > costs) {
    vector<int> ans = costs[0];
    for (int node = 1; node < costs.size(); node++) {
        vector<int> cur(ans.size(), INF);

        for (int last_sz = c-1; last_sz >= 0; last_sz--) {
            for (int get = 0; get <= last_sz; get++) {
                cur[last_sz] = min(cur[last_sz], ans[last_sz - get] + costs[node][get]);
            }
        }

        ans = cur;
    }
    return ans;
}

void dfs(int v, int p = -1) {
    vector<vector<int> > costs;
    for (auto op : e[v]) {
        int u = op.fi;
        if (u == p) continue;
        dfs(u, v);

        vector<int> cur;
        cur.pb(op.se + *min_element(ans[u]+1, ans[u]+c+1)); // choose 0 -> cut edge
        for (int i = 1; i <= c; i++)
            cur.pb(ans[u][i]);
        costs.pb(cur);
    }
//    cerr << "par " << v << '\n';
//    for (auto vec : costs) {
//        cerr << "{";
//        for (int x : vec) cerr << x << ",";
//        cerr << "}\n";
//    }

    if (costs.size() == 0) { // leaf
        ans[v][1] = 0;
        return;
    }

    vector<int> cur = knapsack(costs);

    for (int i = 0; i < c; i++)
        ans[v][i+1] = cur[i]; // add current node to the knapsack

//    cerr << "res: ";
}

void solve() {
    cin >> n >> c;
    for (int i = 0; i < n-1; i++) {
        int u, v, l; cin >> u >> v >> l;
        e[u].pb(mp(v, l));
        e[v].pb(mp(u, l));
    }

    memset(ans, INF, sizeof(ans));
    dfs(1);

    int out = INF;
    for (int i = 1; i <= c; i++)
        out = min(out, ans[1][i]);
    cout << out << '\n';
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