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
#define MAXN 200005
//#define MOD 998244353LL
#define MOD 1000000007LL

// z <= x+y-1
// c <= z <= min(d, x+y-1)
// c <= x+y-1
// c-x+1 <= y

// x+y-1 >= d
// y >= d-x+1

long long clamp(long long x, long long y, long long v) {
    if (v <= x) v = x;
    if (v >= y) v = y;
    return v;
}

void solve() {
    long long ans = 0;
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    for (long long x=a; x <= b; x++) {
        // d-x+1 <= y <= c: z bound by d
        // max(b, c-x+1) <= y <= d-x:  z bound by x+y-1

        long long inc_lb = max(b, c-x+1);
        long long inc_ub = min(c, (d-x));

        if (inc_ub-inc_lb+1 > 0) {
            ans += (clamp(c,d,x+inc_lb-1)-c+1 + clamp(c,d,x+inc_ub-1)-c+1) * (inc_ub-inc_lb+1) / 2;
        }

        long long flat_lb = max(b, d-x+1);
        long long flat_ub = c;

        if (flat_ub-flat_lb+1 > 0) {
            ans += (clamp(c,d,x+flat_lb-1)-c+1 + clamp(c,d,x+flat_ub-1)-c+1) * (flat_ub-flat_lb+1) / 2;
        }
        cerr << x << '\n';
        cerr << "inc_lb " << inc_lb << ' ' << clamp(c,d,x+inc_lb-1) << '\n';
        cerr << "inc_ub " << inc_ub << ' ' << clamp(c,d,x+inc_ub-1) << '\n';
        cerr << "flat_lb " << flat_lb << ' ' << clamp(c,d,x+flat_lb-1) << '\n';
        cerr << "flat_ub " << flat_ub << ' ' << clamp(c,d,x+flat_lb-1) << '\n';
    }
    cout << ans << '\n';

//    long long ch = 0;
//    for (int x=a; x<=b; x++)
//        for (int y=b; y<=c; y++)
//            for (int z=c; z<=d; z++) {
//                if (z<x+y) ch++;
//            }
//    cout << ch << '\n';
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