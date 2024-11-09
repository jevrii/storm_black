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
#define INF 0x3f3f3f3f3f3f3f3f
//#define MOD 998244353LL
#define MOD 1000000007LL

int n;
int a[200005], b[200005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b+1, b+1+n);

    int lo = 0, hi = n+1;
    while (hi-lo>1) {
        int mi = (hi+lo)/2;
        long long x = b[mi];
        bool bad = 0;
        for (int i = 1; i <= n; i++) {
            if (i == mi){
                continue;
            }
            if (b[i] <= x) {
                x += b[i];
            }
            else
                bad = 1;
        }
        if (not bad)
            hi = mi;
        else
            lo = mi;
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= b[hi])
            ans.pb(i);
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i+1==ans.size()];
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
//        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}