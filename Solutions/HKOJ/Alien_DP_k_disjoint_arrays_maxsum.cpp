#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

int n, k;
long long a[200005];

pii work(long long lambda) {
    pii prev = mp(a[0]-lambda, 1), mx = mp(max(0LL,a[0]-lambda), (a[0]-lambda)>0);
    for (int i = 1; i < n; i++) {
        pii cur = max(mp(a[i] + prev.fi, prev.se), mp(a[i] + mx.fi - lambda, mx.se+1));
        mx = max(mx, cur);
        prev = cur;
    }
    return mx;
}

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    k=1;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long hi = 1e9, lo = -1;
    while (hi - lo > 1) {
        long long mi = (hi+lo)/2;
        auto op = work(mi);
        if (op.se <= k) hi = mi;
        else lo = mi;
    }

    auto op = work(hi);
    cout << op.fi+op.se*hi << '\n';
}
