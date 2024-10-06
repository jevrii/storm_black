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

int n;
long long a[MAXN];
long long d;

bool check(long long x) {
    long long cur = x;
    if (cur > d) return 0;
    for (int i = 1; i < n; i++) {
        if (cur % a[i]) {
            cur = cur + a[i]-cur%a[i];
        }
        if (cur > d) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long hi = d/a[0]+3, lo = 0;
    while (hi-lo > 1) {
        long long mi = (hi+lo)/2;
        if (check(a[0]*mi)) lo=mi;
        else hi=mi;
    }
    cout << lo*a[0] << '\n';
}

/*
 * dp[pos] = dp[k]-ps[k] + ps[pos]
 *
 *
 */

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