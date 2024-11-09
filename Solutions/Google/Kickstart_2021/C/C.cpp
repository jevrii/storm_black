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
//#define MOD 998244353LL
#define MOD 1000000007LL

#define MAXN 1000006

double w, e;
int nxt[65][65][65];
double dp[65][65][65];

long double f(int r, int s, int p, int ch) {
    if (r+s+p == 0) {
        return w/3 + e/3;
    }
    double pr[3];
    pr[0] = 1.0*s/(r+s+p);
    pr[1] = 1.0*p/(r+s+p);
    pr[2] = 1.0*r/(r+s+p);

    return w*pr[(ch+1)%3] + e*pr[ch];
}

double dpf(int pos, int r = 0, int s = 0, int p = 0) {
    if (pos == 60)
        return 0;
    double &ans = dp[r][s][p];
    if (ans >= 0)
        return ans;
    pair<double, int> mx = {-1, -1};
    mx = max(mx, {f(r,s,p,0) + dpf(pos+1, r+1, s, p), 0});
    mx = max(mx, {f(r,s,p,1) + dpf(pos+1, r, s+1, p), 1});
    mx = max(mx, {f(r,s,p,2) + dpf(pos+1, r, s, p+1), 2});

    nxt[r][s][p] = mx.se;
    return ans = mx.fi;
}

void solve() {
    for (int i = 0; i < 65; i++)
        for (int j = 0; j < 65; j++)
            for (int k = 0; k < 65; k++) {
                dp[i][j][k] = -1;
            }
    cin >> w >> e;
    dpf(0);
    int cnt = 0;
    string out = "RSP";
    int r = 0, s = 0, p = 0;
    while (cnt < 60) {
        cout << out[nxt[r][s][p]];
        if (nxt[r][s][p] == 0)
            r++;
        else if (nxt[r][s][p] == 1)
            s++;
        else if (nxt[r][s][p] == 2)
            p++;
        cnt++;
    }
    cout << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    auto start_time = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, x;
    cin >> t >> x;
    for (int no = 1; no <= t; no++) {
        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}