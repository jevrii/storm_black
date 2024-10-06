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

int n;
long long r1, r2, r3, d;
long long a[MAXN];
long long dp[MAXN][2];

long long dpf(int x, int p) {
    if (dp[x][p] != -1)
        return dp[x][p];

    if (x == n) {
        long long l1 = a[x]*r1 + r3 + p * (d + r1); // single kill each, awp boss
        long long l2 = a[x]*r1 + r1 + 2*d+(1+p)*r1; // single kill each, single boss
        long long l3 = r2 + 2*d+(1+p)*r1; // laser

        return dp[x][p] = min({l1, l2, l3});
    }

    if (p) {
        long long l1 = a[x]*r1 + r3 + dpf(x+1, 0) + d; // single kill each, awp boss
        long long l2 = a[x]*r1 + r1 + dpf(x+1, 0) + d + r1; // single kill each, single boss
        long long l3 = r2 + dpf(x+1, 0) + d + r1; // laser

        return dp[x][p] = min({l1, l2, l3}) + (2*d+r1);
    }
    else {
        long long l1 = a[x]*r1 + r3 + dpf(x+1, 0) + d; // single kill each, awp boss
        long long l2 = a[x]*r1 + r1 + dpf(x+1, 1) + d; // single kill each, single boss
        long long l3 = r2 + dpf(x+1, 1) + d; // laser

        return dp[x][p] = min({l1, l2, l3});
    }
}

void solve() {
    cin >> n >> r1 >> r2 >> r3 >> d;
    r1 = min(r1, r3);
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << dpf(1, 0) << '\n';
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