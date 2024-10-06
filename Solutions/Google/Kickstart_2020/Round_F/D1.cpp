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
#define MAXN 1000006
//#define MOD 998244353LL
#define MOD 1000000007LL

map<pair<vector<int>, int>, long double> dp;
vector<int> a;
int n, m, k;

long double dpf(vector<int> v, int x=0) {
    if (v == a)
        return 0;
    if (dp.count(mp(v, x))) return dp[mp(v, x)];

    long double exp = 0;
    for (int i = 0; i < m; i++) {
        vector<int> nxt = v;
        nxt[i]++;
        sort(nxt.begin(), nxt.end());
        int bad = 0;
        for (int i = 0; i < m; i++)
            if (nxt[i] > a[i]) {
                bad = 1;
            }
        if (x < 100) {
            if (bad) {
                exp += 1.0/m * (1 + dpf(v, x+1));
            }
            else {
                exp += 1.0/m * (1 + min(dpf(nxt), dpf(v, x+1)));
            }
        }
        else {
            if (not bad) {
                exp += 1.0/m * (1 + dpf(nxt));
            }
        }
    }

    return dp[mp(v, x)] = exp;
}

void solve() {
    dp.clear();
    cin >> n >> m >> k;
    a = vector<int>(m);
    if (n > 6) return;
    for (int i = 0; i < k; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    cout << fixed << setprecision(12) << dpf(vector<int>(m)) << '\n';
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