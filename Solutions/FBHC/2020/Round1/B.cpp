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
#define MAXN 3000006
//#define MOD 998244353LL
#define MOD 1000000007LL

int n, m;
int p[MAXN], q[MAXN];

void get_input() {
    int k, s;
    long long a, b, c, d;
    cin >> n >> m >> k >> s;

    for (int i = 0; i < k; i++)
        cin >> p[i];
    cin >> a >> b >> c >> d;
    for (int i = k; i < n; i++)
        p[i] = (a*p[i-2]+b*p[i-1]+c) % d + 1;

    for (int i = 0; i < k; i++)
        cin >> q[i];
    cin >> a >> b >> c >> d;
    for (int i = k; i < m; i++)
        q[i] = (a*q[i-2]+b*q[i-1]+c) % d + 1;
}

int f(int a, int b, int c) {
    return min(abs(b-a)+abs(c-a), abs(c-b)+abs(c-a));
}

bool ok(int k) {
//    cerr << "----\ntry " << k << '\n';
    int cur = 0;
    for (int g = 0; g < n; g++) {
        int lo = p[g], hi = p[g];
        while (cur < m) {
            if (f(min(lo, q[cur]), p[g], max(hi, q[cur])) > k) break;
//            cerr << p[g] << " do " << q[cur] << '\n';
            lo = min(lo, q[cur]);
            hi = max(hi, q[cur]);
            cur++;
        }
    }
    return cur==m;
}

void solve() {
    get_input();
    sort(p, p+n);
    sort(q, q+m);
//    for (int i = 0; i < n; i++) cout << p[i] << ' '; cout << '\n';
//    for (int i = 0; i < m; i++) cout << q[i] << ' '; cout << '\n';

    int hi=1000000005, lo=0;
    while (hi-lo>1) {
        int mi = (hi+lo)/2;
        if (ok(mi)) hi = mi;
        else lo = mi;
    }
    cout << hi << '\n';
}

int main() {
#ifdef LOCAL
    freopen("dislodging_logs_input.txt", "r", stdin);
//    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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