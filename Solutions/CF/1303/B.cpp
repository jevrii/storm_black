#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define MAXN 200005
#define INF 0x3f3f3f3f
#define MOD 1000000007LL

long long n, g, b;

bool ok(long long k) {
    long long len = k;
    long long cg, cb;
    cg = len/(b+g) * g;
    cb = len/(b+g) * b;

    k %= b+g;

    cg += min(g,k);
    k -= min(g,k);
    cb += k;

    return (cg*2 >= n && len >= n);
}

void solve() {
    cin >> n >> g >> b;

    long long hi = 2e18, lo = 0;
    while (hi-lo > 1) {
        long long mi = (hi+lo)/2;
        if (ok(mi)) hi = mi;
        else lo = mi;
    }
    cout << hi << '\n';
}

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif

    int t; cin >> t;
    while (t--)
        solve();

}
