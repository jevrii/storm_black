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
#define MAXN 300005
//#define MOD 998244353LL
#define MOD 1000000007LL

int n, q;
int a[MAXN+5];
int T[MAXN+5];

int sum(int x) {
    int ans = 0;
    for (; x; x -= x&-x)
        ans += T[x];
    return ans;
}

void add(int x, int v) {
    for (; x < MAXN; x += x&-x)
        T[x] += v;
}

int lb_search(int v) {
    int sum = 0, pos = 0;
    for (int i = __lg(MAXN); i >= 0; i--) {
        if (pos + (1<<i) < MAXN and sum + T[pos + (1<<i)] >= v) {
            sum += T[pos + (1<<i)];
            pos += (1<<i);
        }
    }
    return pos;
}

vector<pii> queries;
vector<int> qs[MAXN];
map<pii, int> ans;

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = i - a[i];
    }
    // input queries
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        int l = x+1, r = n-y;
        queries.pb(mp(l, r));
        qs[r].pb(l);
    }

    for (int r = 1; r <= n; r++) {
        if (a[r] >= 0) {
            int pos = lb_search(a[r]);
//            cerr << r << ' ' << pos << '\n';
            pos = min(pos, r);
            if (pos >= 1) {
//                cerr << "increase " << 1 << ' ' << pos << '\n';
                add(1, 1);
                add(pos+1, -1);
            }
        }

        for (int l : qs[r]) {
            ans[mp(l, r)] = sum(l);
        }
    }

    for (auto op : queries)
        cout << ans[op] << '\n';
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