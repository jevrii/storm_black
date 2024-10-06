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

#define DEBUG 0
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

pii a[MAXN];
int n, k;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    sort(a+1, a+1+n);

    int p = 1, ans = 0, br = -1;

    while (p <= n) {
        cerr << "cur " << p << ' ' << a[p].fi << ' ' << a[p].se << '\n';
        if (a[p].se-a[p].fi >= k) {
            ans += (a[p].se-a[p].fi) / k;
            a[p].fi = a[p].se - (a[p].se-a[p].fi)%k;
            if (a[p].fi == a[p].se)
                p++;
        }
        else {
            br = a[p].fi + k;
            cerr << "br " << br << '\n';
            cerr << "p " << p << ' ' << a[p].fi << '\n';
            ans++;
            while (p <= n && a[p].se <= br) {
                cerr << "inc\n";
                p++;
            }
            if (a[p].fi <= br) {
                cerr << "modify p" << p << ' ' << br << '\n';
                a[p].fi = br;
            }
        }
        cerr << "ans " << ans << "\n\n";
    }

    cout << ans << '\n';
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