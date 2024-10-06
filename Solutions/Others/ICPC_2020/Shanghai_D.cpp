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

long double len, p1, p2, v1, v2;

long double f1(long double a) {
    return min(
            (a-p1)/v1 + a/v1,
            p1/v1 + a/v1
    );
}

long double f2(long double a) {
    return min(
            (p2-a)/v2 + (len-a)/v2,
            (len-p2)/v2 + (len-a)/v2
    );
}

long double g(long double a){
    return max(f1(a), f2(a));
}

void solve() {
    cin >> len >> p1 >> v1 >> p2 >> v2;
    if (p1 > p2) {
        swap(p1, p2);
        swap(v1, v2);
    }

    long double lo = p1, hi = p2;
    int iter = 100;
    while (iter--) {
        long double m1 = (lo*2+hi)/3;
        long double m2 = (lo+hi*2)/3;
        if (g(m1) > g(m2)) lo = m1;
        else hi = m2;
    }

//    cerr << p1 << ' ' << p2 << '\n';

    long double ans = g(lo);
//    long double ans = 999999999999999;
    ans = min({ans, p1/v1 + len/v1, (len-p1)/v1 + len/v1});
    ans = min({ans, p2/v2 + len/v2, (len-p2)/v2 + len/v2});
    ans = min(ans, max((len-p1)/v1, p2/v2));

    cout << fixed << setprecision(12) << ans << '\n';
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