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

long double f (int x, int y) {
    if (x == 1 and y == 1) return 1;
    if (x < 1 or y < 1) return 0;
    if (u <= x and x <= d and l <= y and y <= r) return 0;

    if (x == h) return f(x, y - 1) + 0.5 * f(x - 1, y);
    if (y == w) return f(x - 1, y) + 0.5 * f(x, y - 1);

    if (x > d) {
        if (y < l) return path(1, 1, x, y);
        if (y > r) return path(1, r+1, x, y);
        return path()
    }

}

void solve() {
    cin >> w >> h;
    cin >> l >> u >> r >> d;

    if (l == 1 and u == 1) {
        cout << 0 << '\n';
        return;
    }

    cout << fixed << setprecision(12) << 0.5*f(d, l-1) + f(d, w) << '\n';
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