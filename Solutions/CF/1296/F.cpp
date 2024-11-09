#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
#define INF 0x3f3f3f3f

#define MAXN 200005

int n, m;
vector<pii> e[MAXN];
int col[MAXN];
pii par[MAXN];

void dfs(int v, int p = -1) {
    for (auto op : e[v]) {
        int u, id; tie(u, id) = op;
        if (u != p) {
            par[u] = mp(v, id);
            dfs(u, v);
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0, u, v; i < n-1; i++) {
        cin >> u >> v;
        e[u].pb({v, i});
        e[v].pb({u, i});
    }
    fill(col, col+n, 1);

    cin >> m;
    vector<pair<pii, int> > qs;
    for (int i = 0, u, v, c; i < m; i++) {
        cin >> u >> v >> c;
        qs.pb(mp(mp(u, v), c));
        dfs(u);
        int cur = v;
        while (cur != u) {
            int id = par[cur].se;
            col[id] = max(col[id], c);
            cur = par[cur].fi;
        }
    }

    for (int i = 0, u, v, c; i < m; i++) {
        tie(u, v) = qs[i].fi;
        c = qs[i].se;
        dfs(u);
        int mx = INF;
        int cur = v;
        while (cur != u) {
            int id = par[cur].se;
            mx = min(mx, col[id]);
            cur = par[cur].fi;
        }
        if (mx != c) {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int i = 0; i < n-1; i++)
        cout << col[i] << " \n"[i==n];



}
