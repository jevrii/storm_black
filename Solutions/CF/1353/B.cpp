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

int a[MAXN], b[MAXN];
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);
    reverse(b, b + n);
    int ans = accumulate(a, a+n, 0LL);
    int cur = ans;
    for (int i = 1; i <= k; i++) {
        cur -= a[i-1];
        cur += b[i-1];
        ans = max(ans, cur);
    }

    cout << ans << '\n';

//    cout << accumulate(a, a+n-k, 0LL) + accumulate(b+n-k, b+n, 0LL) << '\n';
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