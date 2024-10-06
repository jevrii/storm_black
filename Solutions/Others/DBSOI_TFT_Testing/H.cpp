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

#define MAXN 200005
#define INF 0x3f3f3f3f
//#define MOD 998244353LL
#define MOD 1000000007LL

int n, b, target;
long long dp[105][105][105];
long long pp[105];

long long dpf(int pos, int mod, int sum) {
    if (pos == n) {
        return (sum == target && mod == 0);
    }

    if (dp[pos][mod][sum] != -1)
        return dp[pos][mod][sum];

    long long ret = 0;

    for (int dig = 0; dig < b; dig++) {
        ret += dpf(pos + 1, (mod + dig * pp[pos]) % target, sum + dig);
    }

    return dp[pos][mod][sum] = ret;
}

// brute force
vector<int> v;
long long bf_ans;

void dfs(int lay) {
    if (lay == n) {
        int val = 0, sum = 0;
        for (int i = 0, p = 1; i < n; i++) {
            val += v[i] * p;
            sum += v[i];
            p *= b;
        }
        if (sum)
            bf_ans += (val % sum == 0);
    }
    else {
        for (int dig = 0; dig < b; dig++) {
            v.pb(dig);
            dfs(lay + 1);
            v.pop_back();
        }
    }
}

void solve() {
    cin >> n >> b;

    long long ans = 0;
    pp[0] = 1;
    for (int i = 1; i <= n; i++)
        pp[i] = pp[i-1] * b;

    for (int sum = 1; sum <= n*(b-1); sum++) {
        target = sum;
        memset(dp, -1, sizeof(dp));
        ans += dpf(0, 0, 0);
    }

    cout << ans << '\n';
//    dfs(0);
//    cout << bf_ans << '\n';
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