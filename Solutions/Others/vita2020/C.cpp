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

//int n, m, k;
//int a[255][255];

int sim(int x) {
    int nxt = rand(1, x);
    if (nxt == 1) return 1;
    return 1 + sim(nxt);
}

void solve() {
    int s;
    cin >> s;
    if (s <= 3) {
        if (s == 1) cout << 1 << '\n';
        if (s == 2) cout << 2 << '\n';
        if (s == 3) cout << 2 << '\n';
        return;
    }
    int mx = INF;
    for (int iter = 0; iter < 10; iter++) {
        int cnt = 0;
        for (int i = 0; i < 10000; i++) {
            cnt += sim(s);
        }
//        cout << cnt/10000.0 << '\n';
        mx = min(mx, (int)round(cnt/10000.0));
    }
    cout << mx << '\n';
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