#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize ("trapv")
using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;

#define MAXN 1000006
#define INF 0x3f3f3f3f
//#define MOD 998244353LL
#define MOD 1000000007LL

vector<int> v, a;
vector<int> child[MAXN];

long long f(int x) {
    if (child[x].size() == 0)
        return 1;

    vector<vector<long long>> dp(child[x].size(), vector<long long> (3));

    dp[0][0] = f(child[x][0]);
    dp[0][1] = dp[0][0];
    dp[0][2] = (dp[0][0] * (x == 0));

    for (int i = 1; i < child[x].size(); i++) {
        int y = child[x][i];
        int ff = f(y);
        for (int cur = 0; cur < 3; cur++) {
            dp[i][cur] = 0;
            for (int pre = 0; pre < 3; pre++) {
                if (pre == cur) continue;
                (dp[i][cur] += dp[i-1][pre]) %= MOD;
            }
            (dp[i][cur] *= ff) %= MOD;
        }
    }

    if (x == 0) {
        long long ret = 0;
        for (int i = 0; i < 3; i++) {
            (ret += dp[child[x].size()-1][i]) %= MOD;
        }
        return ret;
    }
    return (dp[child[x].size()-1][0] + dp[child[x].size()-1][1]) % MOD;
}

void solve() {
    int T;
    string s;
    cin >> T >> s;

    v.pb(0);
    int cur = 1;
    for (char c : s) {
        if (c == '(') {
            child[v.back()].pb(cur);
            v.pb(cur);
            a.pb(cur);
            cur++;
        }
        else {
            a.pb(v.back());
            v.pop_back();
        }
    }
    v.pop_back();

    if (s.size() == 2) {
        cout << 1 << '\n';
        if (T == 2) {
            cout << 1 << '\n';
        }
        return;
    }

    bool have_pos = 0, have_even = 0;
    for (int i = 1; i <= s.size()/2; i++) {
        if (child[i].size()) {
            have_pos = 1;
            if (child[i].size() % 2 == 0) {
                have_even = 1;
            }
        }
    }

    if (not have_pos or not have_even) {
        cout << 2 << '\n';
        if (T == 2) {
            cout << 2 << '\n';
        }
        return;
    }

    cout << 3 << '\n';
    if (T == 2)
        cout << f(0) << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
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