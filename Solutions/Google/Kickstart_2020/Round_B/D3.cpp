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

long double path (int x, int y, bool use_x = 0) { // x fixed
    if (x == 1 and y == 1) return 1;
    if (x < 1 or y < 1 or x > h or y > w) return 0;
    if (u <= x and x <= d and l <= y and y <= r) return 0;

    int n = x+y-2;
    int r = x-1;
    if (use_x) r = y-1;

    if (n == cN+1 && cR == r) {
//        cerr << "fast skip\n";
        cur = (cN+1.0L)/(2.0L*(cN-cR+1))*cur;
        cN = n;
        cR = r;
        return cur;
    }
    else {
        cerr << "slow " << n << ' ' << r << '\n';
        long double ret = 1;
        for (int i = 1; i <= n; i++) {
            if (i <= r) ret /= i;
            else ret /= i-r;
            ret *= 0.5;
            ret *= i;
        }

        cN = n;
        cR = r;
        return cur = ret;
    }
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

    cerr << "stage 1 " << ans << '\n';

    for (int i = r+1; i < w; i++) {
        int x = u-1, y = i;
        cerr << "add path1 " << x <<' '<< y << '\n';
        ans += path(x, y) * 0.5;
    }

    if (r < w) {
        for (int i = 1; i < u; i++) {
            cerr << "add path2 " << i <<' '<< w-1 << '\n';
            ans += 0.5*path(i, w-1, 1);
        }
    }

    cout << fixed << setprecision(12) << ans << '\n';
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

//    for (int i = 1; i <= 10; i++) {
//        for (int j = 1; j <= 10; j++) {
//            cout << path(i, j) << ' ';
//        }
//        cout << '\n';
//    }

}