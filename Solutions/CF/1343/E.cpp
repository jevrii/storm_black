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

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 500005
#define MOD 998244353LL

vector<int> e[MAXN];
int n, m, a, b, c, vis[MAXN];
int d[3][MAXN];
long long p[MAXN], ps[MAXN];

void bfs(int st, int id) {
    queue<int> q;

    q.push(st);
    fill(vis+1, vis+1+n, 0);
    vis[st] = 1;
    d[id][st] = 0;

    while (q.size()) {
        int t = q.front(); q.pop();
        for (int u : e[t]) {
            if (not vis[u]) {
                q.push(u);
                vis[u] = 1;
                d[id][u] = d[id][t] + 1;
            }
        }
    }
}


void solve() {
    cin >> n >> m >> a >> b >> c;

    for (int i = 0; i < m; i++)
        cin >> p[i];
    sort(p, p + m);
    partial_sum(p, p+m, ps+1);

    for (int i = 1; i <= n; i++)
        e[i].clear();

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    bfs(a, 0);
    bfs(b, 1);
    bfs(c, 2);

//    cerr << "ps: ";
//    for (int i = 0; i <= m; i++) cerr << ps[i] << ' '; cerr << '\n';

    long long ans = INF;
    for (int i = 1; i <= n; i++) {
        if (d[0][i]+d[1][i]+d[2][i] > m) continue;
//        cout << d[0][i] << ' ' << 2*d[1][i] << ' ' << d[2][i] << ' ' << d[0][i]+d[1][i]+d[2][i] << ' ' << ps[d[1][i]] << '\n';

        ans = min(ans, ps[d[0][i]+d[1][i]+d[2][i]] + ps[d[1][i]]);
    }

    cout << ans << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }
}