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
#define MAXN 500005
#define MOD 998244353LL

void solve() {
    long long sgn = 0, mx = 0, ans = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        if (x/abs(x) != sgn) {
            ans += mx;
            mx = x;
            sgn = x/abs(x);
        }
        else {
            mx = max(mx, x);
        }
    }
    cout << ans+mx << '\n';
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
//        cout << "Case #" << no << ": ";
        solve();
    }
}