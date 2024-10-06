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

int cnt[MAXN];
int n, k;
string s;

void solve() {
    cin >> n >> k;
    cin >> s;

    for (int i = 0; i < n; i++)
        cnt[i] = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt[i/k]++;
        }
    }

    int ans = INF;
    int base = count(s.begin(), s.end(), '1');

    for (int mod = 0; mod < k; mod++) {
        vector<int> v;
        for (int i = mod; i < n; i += k) {
            if (s[i] == '1') {
                v.pb(-1);
            }
            else {
                v.pb(1);
            }
        }

//        for (int x : v)
//            cerr << x << ' ';
//        cerr << '\n';

        int cur = 0, dp = 0;
        for (int x : v) {
            dp = min(dp + x, x);
            cur = min(cur, dp);
        }
        ans = min(ans, base + cur);
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
    cin >> t;
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}