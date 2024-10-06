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
#define MAXN 100005
#define MOD 998244353LL

string s, t;
int n, m;
long long dp[3005][3005];

long long dpf(int len, int pos) {
    long long ret = 0;
    if (dp[len][pos] != -1) return dp[len][pos];
    if (pos == 0 and len >= m)
        ret += 1;

    if (pos+len < m) { // append char is in prefix
        if (s[len] == t[pos+len]) {
//            cerr << len << ' ' << pos << " call suff 1\n";
            (ret += dpf(len+1, pos)) %= MOD;
        }
    }
    else if (pos+len < n){ // not in prefix but within whole str, do whatever
//        cerr << len << ' ' << pos << " call suff 2\n";
        (ret += dpf(len+1, pos)) %= MOD;
    }

    if (pos >= 1) {
        if (pos-1 < m) { // add first will be in prefix
            if (s[len] == t[pos-1]) {
//                cerr << len << ' ' << pos << " call pref 1\n";
                (ret += dpf(len+1, pos-1)) %= MOD;
            }
//            else {
//                cerr << len << ' ' << pos << " pref " << s[len] << ' ' << t[pos-1] << '\n';
//            }
        }
        else {
//            cerr << len << ' ' << pos << " call pref 2\n";
            (ret += dpf(len+1, pos-1)) %= MOD;
        }
    }

    return dp[len][pos] = ret;
}

/*
 *     p
 *     ??
 * abcdef
 *
 */

void solve() {
    cin >> s >> t;
    n = s.length();
    m = t.length();
    memset(dp, -1, sizeof(dp));

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (i >= m || s[0] == t[i])
            (ans += 2*dpf(1, i)) %= MOD;
//        (ans += dpf(0, i)) %= MOD;
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