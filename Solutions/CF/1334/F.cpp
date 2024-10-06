#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

#define DEBUG 0
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 500005
#define MOD 998244353LL

int n, m;
vector<int> a, b, cost;
map<int, vector<int> > pos_at_value;

bool valid() {
    int cur = 0;
    for (int x : a) {
        if (b[cur] == x)
            cur++;
        if (cur >= m) {
            return 1;
        }
    }
    return 0;
}

struct BinaryIndexedTree{
    long long T[MAXN] = {0};
    void add (int x, long long v) {
        for (++x; x < MAXN; x += x & -x)
            T[x] += v;
    }

    long long sum (int x) {
        long long ret = 0;
        for (++x; x; x -= x & -x)
            ret += T[x];
        return ret;
    }
};


struct SegmentTree {
    vector<long long> T;
    vector<int> leaf;

    void build(int id = 1, int l = 0, int r = MAXN) {
        if (id == 1) {
            T.resize(MAXN << 2);
            leaf.resize(MAXN);
        }
        T[id] = INF;
        if (l+1 == r) {
            leaf[l] = id;
            return;
        }
        build(id << 1, l, l + r >> 1);
        build(id << 1 | 1, l + r >> 1, r);
    }

    void update(int x, long long val) {
        T[leaf[x]] = val;
        for (int cur = leaf[x] / 2; cur; cur /= 2) {
            T[cur] = min(T[cur * 2], T[cur * 2 + 1]);
        }
    }

    long long ask(int x, int y, int id = 1, int l = 0, int r = MAXN) {
        if (y <= l || r <= x)
            return INF; // sentiel value not affecting output  // ###
        if (x <= l && r <= y)
            return T[id];

        return min(ask(x, y, id << 1, l, l + r >> 1),
                   ask(x, y, id << 1 | 1, l + r >> 1, r)); // ###
    }
};

void solve() {
    cin >> n;
    a.resize(n), cost.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos_at_value[a[i]].pb(i);
    }
    for (int i = 0; i < n; i++) cin >> cost[i];
    cin >> m;
    b.resize(n);
    for (int i = 0; i < m; i++) cin >> b[i];

    if (not valid()) {
        cout << "NO\n";
        return;
    }
    else {
        cout << "YES\n";
    }

    BinaryIndexedTree ps;
    SegmentTree T;
    T.build();

    deque<pii> q;

    for (int i = 0; i < n; i++) {
        ps.add(i, cost[i]);
        q.pb(mp(a[i], i));
    }

    sort(q.begin(), q.end());

    vector<pair<int, long long> > prev_candidates;

    for (int iter = 0; iter < m; iter++) {
        int target = b[iter];
        cerr << "cur " << target << '\n';

        for (auto op : prev_candidates) {
            cerr << "  update " << op.fi << ' ' << op.se << '-' << ps.sum(op.fi) << ' ' << op.se - ps.sum(op.fi) << '\n';
            T.update(op.fi, op.se - ps.sum(op.fi)); // pos, value
        }

        vector<pair<int, long long> > cur_candidates;

        for (int pos : pos_at_value[target]) {
            cur_candidates.pb({pos, ps.sum(pos-1) + !!iter * T.ask(0, pos)});
            cerr << "  ps " << ps.sum(pos-1) << '\n';
            cerr << "  candidate " << pos << ' ' << ps.sum(pos-1) + !!iter * T.ask(0, pos) << '\n';
        }

        for (auto op : prev_candidates) {
            T.update(op.fi, INF); // pos, value
        }

        swap(cur_candidates, prev_candidates);

        while (q.size() && q.front().fi <= target) {
            int pos = q.front().se;
            if (cost[pos] > 0) {
                ps.add(pos, -cost[pos]);
                cerr << "  remove " << pos << ' ' << a[pos] << ' ' << -cost[pos] << '\n';
            }
            q.pop_front();
        }
    }

    long long ans = INF;
    for (auto op : prev_candidates)
        ans = min(ans, op.se + ps.sum(n-1) - ps.sum(op.fi));
    cout << ans << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }
}