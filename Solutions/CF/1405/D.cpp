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
#define MAXN 100005
//#define MOD 998244353LL
#define MOD 1000000007LL

int n, a, b, da, db;
vector<int> e[MAXN];

void dfs(int v, int p, vector<int>& dist, int dep=0) {
    dist[v] = dep;
    for (int u : e[v]) {
        if (u-p) {
            dfs(u, v, dist, dep+1);
        }
    }
}

void solve() {
    cin >> n >> a >> b >> da >> db;
    for (int i = 1; i <= n; i++)
        e[i].clear();
    for (int i = 0, u, v; i < n-1; i++) {
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    vector<int> dist_from_b(n+1);
    dfs(b, -1, dist_from_b);

    if (dist_from_b[a] <= da) { // can capture from first move
        cout << "Alice\n";
        return;
    }

    if (db <= 2*da) { // cannot trigger loop
        cout << "Alice\n";
        return;
    }

    int deepest = max_element(dist_from_b.begin(), dist_from_b.end())-dist_from_b.begin();
    vector<int> deep2(n+1);
    dfs(deepest, -1, deep2);

    int diameter = *max_element(deep2.begin(), deep2.end());

    if (da >= (diameter+1)/2) {
        cout << "Alice\n";
        return;
    }

    cout << "Bob\n";
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