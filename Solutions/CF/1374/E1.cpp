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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 200005
#define MOD 998244353LL

#define SHIFT 20000020

int t[MAXN], a[MAXN], b[MAXN];
int n, k;
long long ps[MAXN], psa[MAXN], psb[MAXN];

void solve() {
    cin >> n >> k;
    int ca=0, cb=0;
    vector<int> both, oa, ob;

    for (int i = 0; i < n; i++) {
        cin >> t[i] >> a[i] >> b[i];
        if (a[i] == 1 and b[i] == 1) both.pb(t[i]);
        if (a[i] == 1 and b[i] == 0) oa.pb(t[i]);
        if (a[i] == 0 and b[i] == 1) ob.pb(t[i]);

        ca+=a[i];
        cb+=b[i];
    }

    if (ca<k or cb<k) {
        cout << -1 << '\n';
        return;
    }

    sort(both.begin(), both.end());
    sort(oa.begin(), oa.end());
    sort(ob.begin(), ob.end());

    partial_sum(both.begin(), both.end(), ps+1);
    partial_sum(oa.begin(), oa.end(), psa+1);
    partial_sum(ob.begin(), ob.end(), psb+1);

    long long ans = INF;

    for (int choose = 0; choose <= both.size(); choose++) {
        int rem = max(0, k-choose);
        if (oa.size() < rem || ob.size() < rem) continue;
        long long cur = ps[choose]+psa[rem]+psb[rem];
        ans = min(ans, cur);
    }

    cout << ans << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
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