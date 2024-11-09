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

#define INF 0x3f3f3f3f3f3f3f3f
//#define MOD 998244353LL
#define MOD 1000000007LL

#define MAXN 1000006

int n, k;
string s;

long long f(string s) {
    long long ret = 0;
    for (long long i = s.size()-1, c = 1; i >= 0; i--, (c *= k) %= MOD) {
        (ret += (s[i]-'a')*c%MOD) %= MOD;
    }
    return ret+1;
}

void solve() {
    cin >> n >> k;
    cin >> s;

    if (n == 1) {
        cout << s[0]-'a' << '\n';
        return;
    }

    long long ans = 0;

    string h1 = s.substr(0, n/2);
    string h2 = s.substr((n+1)/2);

    long long fx = f(h1);

    if (n % 2 == 1) {
        (ans += (s[n/2]-'a')*(fx)%MOD) %= MOD;
        (ans += ('a'+k-1-s[n/2])*(fx-1)%MOD) %= MOD;
    }

    (ans += (fx-1) % MOD) %= MOD;

    reverse(h1.begin(), h1.end());
    if (h1 < h2) {
        ans++;
    }

    cout << ans % MOD << '\n';
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
    cin >> t;
    for (int no = 1; no <= t; no++) {
        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}