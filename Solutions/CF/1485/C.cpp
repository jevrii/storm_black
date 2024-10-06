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

void solve() {
    long long x, y;
    cin >> x >> y;

//    int secret = 0;
//    for (int j = 1; j <= y; j++)
//    for (int i = 1; i <= x; i++)
//        if (i/j == i%j) {
////            cout << i << ' ' << j << '\n';
//            secret++;
//        }

    long long ans = 0;
    long long idx = -1;
    for (long long b = 2; b <= y; b++){
        long long tc = min(b-1, x/(b+1));
        if (x/(b+1) < b-1) {
            idx = b;
            break;
        }
        ans += tc;
    }

//    cerr << idx << ' ' << x/(idx+1) << '\n';

    if (idx != -1) {
        for (int div = x/(idx+1); div >= 1; div--) {
            int lx = min(y+1, max(idx, x/(div+1)));
            int rx = min(y+1, x/div);

//            cerr << div << ' ' << lx << ' ' << rx << ' ' << x/lx << ' ' << x/rx << '\n';

            ans += (rx-lx)*div;

            if (lx > y)
                break;
        }
    }

    cout << ans << '\n';
//    cerr << secret << '\n';
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
    cin >> t;
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}