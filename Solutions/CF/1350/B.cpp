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

vector<int> factors[MAXN];
int a[MAXN], dp[MAXN];
int n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int x : factors[i])
            if (a[x] < a[i]) {
                dp[i] = max(dp[i], dp[x]+1);
            }
    }
    cout << *max_element(dp+1, dp+1+n) << '\n';



}

void precom() {
    for (int i = 1; i < MAXN; i++)
        for (int j = i; j < MAXN; j += i)
            factors[j].pb(i);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    auto start_time = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precom();
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