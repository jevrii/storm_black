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

int p = 59385, n, k;
vector<long long> a, nxt;

int ask(int x) {
#ifdef LOCAL
    int ret = a[x-1];
    for (int i = 0; i < n; i++) {
        if (i == p) {
            nxt[(i+1)%n] += a[i];
        }
        else {
            nxt[(i-1+n)%n] += a[i] / 2;
            nxt[(i+1)%n] += a[i]- (a[i] / 2);
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = nxt[i];
        nxt[i] = 0;
//        cout << a[i] << " \n"[i+1==n];
    }
    return ret;
#else
    cout << "? " << x << endl;
    int _; cin >> _;
    return _;
#endif
}

void solve() {
    cin >> n >> k;
#ifdef LOCAL
    a.resize(n);
    nxt.resize(n);
    for (int i = 0; i < n; i++) {
        a[i] = k;
//        cout << a[i] << " \n"[i+1==n];
    }
#endif
//    for (int iter = 0; iter < 30; iter++) {
//        for (int i = 0; i < n; i++) {
//            if (i == p) {
//                nxt[(i+1)%n] += a[i];
//            }
//            else {
//                nxt[(i-1+n)%n] += a[i] / 2;
//                nxt[(i+1)%n] += a[i]- (a[i] / 2);
//            }
//        }
//        for (int i = 0; i < n; i++) {
//            a[i] = nxt[i];
//            nxt[i] = 0;
//            cout << a[i] << " \n"[i+1==n];
//        }
//    }

    vector<int> gen(n);
    iota(gen.begin(), gen.end(), 1);
    shuffle(gen.begin(), gen.end(), rng);

    int lo = -1, hi = -1;

    for (int i = 0; i < 950; i++) {
        int x = ask(gen[i%gen.size()]);
        if (x < k) lo = gen[i%gen.size()];
        else if (x > k) hi = gen[i%gen.size()];
    }

    lo--; hi--;

    if (hi < lo)
        hi += n;

    while (hi - lo > 1) {
        int mi = (hi + lo) / 2;
        int x = ask(mi%n + 1);
        if (x >= k) hi = mi;
        else lo = mi;
    }

    cout << "! " << hi%n+1 << endl;

//    for (int i = 1; i <= 900; i++) {
//        cout << i << ' ' << pow(1-2*i/100000.0, 950-i) << '\n';
//    }
}

int main() {
#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
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