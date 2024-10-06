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
#define MAXN 200005
#define MOD 998244353LL

long double dp[305][305];
int w, h;
int u, d, l , r;

int cN, cR;
long double cur;

void solve() {
    cin >> w >> h;
    cin >> l >> u >> r >> d;

    if (l == 1 and u == 1) {
        cout << 0 << '\n';
        return;
    }

    memset(dp, 0, sizeof(dp));

    dp[1][1] = 1;

    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) {
            if (i == 1 and j == 1) continue;
            if (u <= i && i <= d && l <= j && j <= r) dp[i][j] = 0;
            else {
                dp[i][j] += (j == w ? 1.0 : 0.5) * dp[i-1][j];
                dp[i][j] += (i == h ? 1.0 : 0.5) * dp[i][j-1];
            }
        }

    cout << fixed << setprecision(12) << dp[h][w] << '\n';

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
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
        cout << "Case #" << no << ": ";
        solve();
    }

}