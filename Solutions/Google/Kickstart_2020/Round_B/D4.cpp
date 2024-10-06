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
#define MAXN 200005
#define MOD 998244353LL

int w, h;
int u, d, l , r;
int cN, cR;
long double cur;
long double fact[MAXN], pow2[MAXN];

long double path (int x, int y, bool use_x = 0) { // x fixed
    if (x == 1 and y == 1) return 1;
    if (x < 1 or y < 1 or x > h or y > w) return 0;
    if (u <= x and x <= d and l <= y and y <= r) return 0;

    int n = x+y-2;
    int r = x-1;

    return expl(fact[n] - fact[r] - fact[n-r] - pow2[n]);
}

void solve() {
    cin >> w >> h;
    cin >> l >> u >> r >> d;

    long double ans = 0;
    for (int i = 1; i < l; i++) {
        int x = d, y = i;
        ans += path(x, y) * 0.5;
    }

    if (d == h) ans = 0;

    for (int i = r+1; i < w; i++) {
        int x = u-1, y = i;
        ans += path(x, y) * 0.5;
    }

    if (r < w) {
        for (int i = 1; i < u; i++) {
            ans += 0.5*path(i, w-1);
        }
    }

    cout << fixed << setprecision(12) << ans << '\n';
}

void init() {
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i-1] + logl(i);
        pow2[i] = pow2[i-1] + logl(2);
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    int t = 1;
    cin >> t;
    for (int no = 1; no <= t; no++) {
        cout << "Case #" << no << ": ";
        solve();
    }
}