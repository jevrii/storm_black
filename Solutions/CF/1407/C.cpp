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
#define MAXN 1000006
//#define MOD 998244353LL
#define MOD 1000000007LL

int n;
int ans[MAXN], secret[MAXN];

int ask(int x, int y) {
#ifdef LOCAL
    return secret[x] % secret[y];
#else
    cout << "? " << x << ' ' << y << endl;
    fflush(stdout);
    int ret; cin >> ret;
    return ret;
#endif
}

void solve() {
    cin >> n;
#ifdef LOCAL
    for (int i = 1; i <= n; i++)
        secret[i] = i;
    shuffle(secret+1, secret+1+n, rng);
#endif
    vector<int> v;
    for (int i = 1; i <= n; i++)
        v.pb(i);
    while (v.size() >= 2) {
        int x = v.back();
        v.pop_back();
        int y = v.back();
        v.pop_back();

        int ax = ask(x, y); // is x large?
        int ay = ask(y, x); // is y large?

        if (ax > ay) { //
            ans[x] = ax;
            v.pb(y);
        }
        else {
            ans[y] = ay;
            v.pb(x);
        }
    }
    int tot = n*(n+1)/2;
    for (int i = 1; i <= n; i++)
        tot -= ans[i];
    for (int i = 1; i <= n; i++)
        if (not ans[i])
            ans[i] = tot;
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
    fflush(stdout);

    for (int i = 1; i <= n; i++)
        cerr << secret[i] << ' '; cerr << endl;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    auto start_time = clock();
#endif
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

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