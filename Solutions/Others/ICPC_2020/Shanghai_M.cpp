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

int nxt_node = 1;
map<string, int> adj[1005];
int sum[1005];

void insert(vector<string> v, int add) {
    int cur = 0;
    for (string s : v) {
        if (!adj[cur].count(s)) {
            adj[cur][s] = nxt_node++;
        }
        cur = adj[cur][s];
        sum[cur] += add;
    }
}

int ans = 0;

void dfs(int v) {
    if (v != 0 and sum[v] == 0) {
        ans++;
        return;
    }
    for (auto op : adj[v])
        dfs(op.se);
}

void solve() {
    int n, m;
    ans = 0;
    cin >> n >> m;
    for (int i = 0; i < 1005; i++) {
        adj[i].clear();
        sum[i] = 0;
    }
    nxt_node = 1;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char &c : s)
            if (c == '/') c = ' ';
        vector<string> v;
        stringstream ss(s);
        string t;
        while (ss >> t)
            v.pb(t);

        insert(v, 0);
    }

    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        for (char &c : s)
            if (c == '/') c = ' ';
        vector<string> v;
        stringstream ss(s);
        string t;
        while (ss >> t)
            v.pb(t);

        insert(v, 1);
    }

    dfs(0);

    cout << ans << '\n';
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