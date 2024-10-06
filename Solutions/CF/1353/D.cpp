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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 2000006
#define MOD 998244353LL

int n, a[MAXN];

void solve() {
    cin >> n;
    auto cmp = [](pii x, pii y) {
        int lx = x.se-x.fi;
        int ly = y.se-y.fi;
        if (lx != ly) return lx < ly;
        return x.fi > y.fi;
    };
    priority_queue<pii, vector<pii>, decltype(cmp) > q(cmp);
    q.push(mp(1, n));
    int cur = 1;

    while (q.size()) {
        int l, r; tie(l, r) = q.top(); q.pop();
        if (r-l+1 <= 0) continue;
        a[(l+r)/2] = cur++;

        q.push(mp(l, (l+r)/2-1));
        q.push(mp((l+r)/2+1, r));
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i==n];
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    auto start_time = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}