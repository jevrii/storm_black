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

int a[10004];
int n, t, m;

void solve() {
    cin >> n >> t >> m;
    iota(a, a+n, 1);
    for (int iter = 0; iter < t; iter++) {
        if (iter % 2 == 0) {
            for (int i = 0; i+1 <= n-1; i+=2) {
                swap(a[i], a[(i+1)%n]);
            }
        }
        else {
            for (int i = n-n%2; i-1 >= 1; i-=2) {
                swap(a[i%n], a[i-1]);
            }
        }

//        for (int i = 0; i < n; i++)
//            cout << a[i] << ' ';
//        cout << '\n';
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == m) {
            cout << a[(i+1+n)%n] << ' ' << a[(i-1+n)%n];
        }
    }
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