#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

struct query{
    int type, x, y, time;
};

struct status{
    int n_comp, col;
};

#define MAXC 2000006

int n, m, q, a[305][305], cur_ncomp[MAXC], to_be_removed[305][305];
vector<query> qlist[MAXC];
vector<status> comp_at_time[MAXC];

struct DSU{
    pii p[305][305];

    void init() {
        for (int i = 1; i <= 300; i++)
            for (int j = 1; j <= 300; j++)
                p[i][j] = mp(i, j);
    }

    pii get(int x, int y) {
        if (mp(x, y) == p[x][y]) return mp(x, y);
        return p[x][y] = get(p[x][y].fi, p[x][y].se);
    }

    bool join(pii a, pii b) {
        a = get(a.fi, a.se), b = get(b.fi, b.se);
        if (a == b) return 0;
        p[a.fi][a.se] = b;
        return 1;
    }

    void reset(int x, int y) {
        p[x][y] = mp(x, y);
    }
}dsu;

int add_res(int x, int y, int c) {
    int ret = 0;
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++) {
            if (abs(dx)+abs(dy) != 1) continue;
            int cx = x + dx, cy = y + dy;
            if (a[cx][cy] == c) {
                // cerr << "join " << "{" << x << "," << y << "}" << "{" << cx << "," << cy << "}" << '\n';
                ret += dsu.join(mp(x, y), mp(cx, cy));
            }
        }
    a[x][y] = c;
    return ret;
}

void work(int c) {
    int n_points = 0, joined = 0;
    vector<pii> points;

    for (auto op : qlist[c]) {
        dsu.reset(op.x, op.y);
        a[op.x][op.y] = -1;
        to_be_removed[op.x][op.y] = 0;
    }

    for (auto op : qlist[c]) {
        if (op.type == -1) {
            to_be_removed[op.x][op.y] = 1;
        }
        else {
            if (c) {
                n_points++;
                joined += add_res(op.x, op.y, c);
                comp_at_time[op.time].pb({n_points - joined, c});
            }
        }
    }

    if (not c) {
        comp_at_time[0].pb({1, 0});
    }

    for (auto op : qlist[c]) {
        dsu.reset(op.x, op.y);
        a[op.x][op.y] = -1;
    }

    n_points = 0;
    joined = 0;

    for (auto op : qlist[c]) {
        if (op.type == 1 and not to_be_removed[op.x][op.y]) {
            n_points++;
            joined += add_res(op.x, op.y, c);
        }
    }

    for (int i = qlist[c].size()-1; i >= 0 && qlist[c][i].type == -1; i--) { // reverse from back
        auto op = qlist[c][i];
        if (a[op.x][op.y] == c) continue;
        comp_at_time[op.time].pb({n_points - joined, c});
        joined += add_res(op.x, op.y, c);
        n_points++;
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;
    dsu.init();

    memset(a, 0, sizeof(a));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            qlist[0].pb({+1, i, j, 0});

    for (int i = 1; i <= q; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        if (a[x][y] == c) continue;
        qlist[a[x][y]].pb({-1, x, y, i});
        a[x][y] = c;
        qlist[a[x][y]].pb({+1, x, y, i});
    }

    memset(a, -1, sizeof(a));

    for (int i = 0; i < MAXC; i++)
        work(i);

//    for (int t = 1; t <= q; t++) {
//        int x, y, type; cin >> x >> y >> type;
//        qlist[1].pb({type, x, y, t});
//    }
//    work(1);

    int ans = 1;
    cur_ncomp[0] = 1;

    for (int i = 1; i <= q; i++) {
//        cerr << "TIME: " << i << '\n';
        for (auto op : comp_at_time[i]) {
//            cerr << "size " << op.n_comp << " from id " << op.col << " old " << cur_ncomp[op.col] << '\n';
            int id = op.col;
            ans -= cur_ncomp[id];
            ans += op.n_comp;
            cur_ncomp[id] = op.n_comp;
        }
        cout << ans << '\n';
    }
}
