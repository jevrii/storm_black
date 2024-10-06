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

#define INF 0x3f3f3f3f
#define MAXN 1000006
//#define MOD 998244353LL
#define MOD 1000000007LL

int s, ra, ca, rb, cb, m;
bool blocked[20][20];
map<pair<long long, pair<pii, bool> >, int> dp;
int xy_to_id[20][20];
vector<int> e[100];

int dpf(long long state, int a, int b, bool turn_a) {
    if (dp.count(mp(state, mp(mp(a, b), turn_a))))
        return dp[mp(state, mp(mp(a, b), turn_a))];
    int ans;
    if (turn_a) { // turn_a
        ans = ~INF;
        for (int u : e[a]) {
            if (not (state & (1LL << u))) {
                ans = max(ans, dpf(state | (1LL << u), u, b, !turn_a)+1);
            }
        }
        if (ans == ~INF) {
            int good = 0;
            for (int u : e[b]) // b cannot move?
                if (not (state & (1LL << u)))
                    good = 1;
            if (good)
                ans = max(ans, dpf(state, a, b, !turn_a));
            else
                ans = 0;
        }
    }
    else { // turn_b
        ans = INF;
        for (int u : e[b]) {
            if (not (state & (1LL << u))) {
                ans = min(ans, dpf(state | (1LL << u), a, u, !turn_a)-1);
            }
        }
        if (ans == INF) {
            int good = 0;
            for (int u : e[a]) // a cannot move?
                if (not (state & (1LL << u)))
                    good = 1;
            if (good)
                ans = min(ans, dpf(state, a, b, !turn_a));
            else
                ans = 0;
        }
    }

    return dp[mp(state, mp(mp(a, b), turn_a))] = ans;
}

void gen_xy() {
    int cur = 0;
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= 2*i-1; j++) {
            xy_to_id[i][j] = cur++;
        }
    }

    for (int i = 0; i < 100; i++)
        e[i].clear();

    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= 2*i-1; j++) {
            int u = xy_to_id[i][j];
            if (j % 2 == 1) {
                if (i < s)
                    e[u].pb(xy_to_id[i+1][j+1]);
            }
            else {
                if (i > 1)
                    e[u].pb(xy_to_id[i-1][j-1]);
            }
            if (j > 1)
                e[u].pb(xy_to_id[i][j-1]);
            if (j < 2*i-1)
                e[u].pb(xy_to_id[i][j+1]);
        }
    }
}

void solve() {
    cin >> s >> ra >> ca >> rb >> cb >> m;
    memset(blocked, 0, sizeof(blocked));
    dp.clear();

    gen_xy();

    long long state = 0;

//    for (int i = 0; i < s*s; i++) {
//        cerr << i << ": ";
//        for (int u : e[i])
//            cerr << u << ' ';
//        cerr << '\n';
//    }

    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        blocked[x][y] = 1;
        state |= (1LL << xy_to_id[x][y]);
    }

    state |= (1LL << xy_to_id[ra][ca]);
    state |= (1LL << xy_to_id[rb][cb]);

    cout << dpf(state, xy_to_id[ra][ca], xy_to_id[rb][cb], 1) << '\n';
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
        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}