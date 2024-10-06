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

#define MAXN 1000006
#define INF 0x3f3f3f3f
//#define MOD 998244353LL
#define MOD 1000000007LL

int nq;
int p[MAXN], dep[MAXN], sz[MAXN];
bool is_root[MAXN], dead[MAXN];
vector<int> e[MAXN];
vector<pair<string, pair<int, pii> > > queries;

int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
}

void join(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return;
    p[x] = y;
}

void dfs(int v, int d = 0) {
    dep[v] = d;
    for (int u : e[v]) {
        dfs(u, d+1);
    }
}

bool seen[MAXN];

void solve() {
    iota(p, p+MAXN, 0);

    cin >> nq;
    for (int i = 0; i < nq; i++) {
        string s;
        int a, b, c;
        cin >> s;
        if (s == "Die") {
            cin >> a;
            dead[get(a)] = 1;
            queries.pb(mp(s, mp(a, mp(-1, -1))));
        }
        else if (s == "Merge") {
            cin >> a >> b >> c;

            b = get(b);
            c = get(c);

            is_root[a] = true;
            if (not dead[b]) {
                join(b, a);
                is_root[b] = false;
                e[a].pb(b);
            }
            if (not dead[c] && b != c) {
                join(c, a);
                is_root[c] = false;
                e[a].pb(c);
            }

            queries.pb(mp(s, mp(a, mp(b, c))));
        }
        else {
            cin >> a;
            if (s == "Create") {
                is_root[a] = true;
            }
            queries.pb(mp(s, mp(a, mp(-1, -1))));
        }
    }

    iota(p, p+MAXN, 0);
    memset(dead, 0, sizeof(dead));

    for (int i = 0; i <= nq; i++) {
        if (is_root[i]) {
            e[1000005].pb(i);
        }
    }

    dfs(1000005);

    for (auto op : queries) {
        string type = op.fi;
        int a, b, c;

        if (type == "Merge") {
            a = op.se.fi;
            b = op.se.se.fi;
            c = op.se.se.se;
        }
        else {
            c = op.se.fi;
        }

        if (type == "Create") {
            sz[c] = 1;
        }
        if (type == "Merge") {
            b = get(b);
            c = get(c);
            sz[a] = 1;
            if (not dead[b]) {
                join(b, a);
                sz[a] += sz[b];
            }
            if (not dead[c] && b != c) {
                join(c, a);
                sz[a] += sz[c];
            }
        }
        if (type == "Root") {
            if (dead[c]) cout << -1 << '\n';
            else if (dead[get(c)]) cout << -1 << '\n';
            else cout << get(c) << '\n';
        }
        if (type == "Die") {
            dead[get(c)] = 1;
        }
        if (type == "Size") {
            if (dead[c]) cout << -1 << '\n';
            else if (dead[get(c)]) cout << -1 << '\n';
            else cout << sz[c] << '\n';
        }
        if (type == "Dist") {
            if (dead[c]) cout << -1 << '\n';
            else if (dead[get(c)]) cout << -1 << '\n';
            else cout << abs(dep[get(c)] - dep[c]) << '\n';
        }
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
//    cin >> t;
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}