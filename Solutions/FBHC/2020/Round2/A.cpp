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

int n;
long long s[MAXN], x[MAXN], y[MAXN];

void get_input() {
    int k;
    long long a, b, c, d;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        cin >> s[i];
    cin >> a >> b >> c >> d;
    for (int i = k+1; i <= n; i++)
        s[i] = (a*s[i-2] + b*s[i-1] + c) % d;

    for (int i = 1; i <= k; i++)
        cin >> x[i];
    cin >> a >> b >> c >> d;
    for (int i = k+1; i <= n; i++)
        x[i] = (a*x[i-2] + b*x[i-1] + c) % d;

    for (int i = 1; i <= k; i++)
        cin >> y[i];
    cin >> a >> b >> c >> d;
    for (int i = k+1; i <= n; i++)
        y[i] = (a*y[i-2] + b*y[i-1] + c) % d;
}

void solve() {
    get_input();
//    for (int i = 1; i <= n; i++) cout << s[i] << ' '; cout << '\n';
//    for (int i = 1; i <= n; i++) cout << x[i] << ' '; cout << '\n';
//    for (int i = 1; i <= n; i++) cout << y[i] << ' '; cout << '\n';

    long long ans = 0;

    // first pass: excess s>x+y to less s<x
    // second pass: excess s>x to less s<x
    // third pass: excess s>x+y to s<y

    long long less = 0, excess = 0, sum = 0, min_sum = 0, max_sum = 0;

    for (int i = 1; i <= n; i++) {
        if (s[i] < x[i]) less += x[i] - s[i];
        if (s[i] > x[i]+y[i]) excess += s[i] - (x[i]+y[i]);
        sum += s[i];
        min_sum += x[i];
        max_sum += x[i]+y[i];
    }
    if (sum < min_sum or sum > max_sum) {
        cout << -1 << '\n';
        return;
    }
    ans += less;
    excess -= less;
    ans += max(0LL, excess);

    cout << ans << '\n';
}

int main() {
#ifdef LOCAL
//    freopen("capastaty_input.txt", "r", stdin);
//    freopen("capastaty_validation_input.txt", "r", stdin);
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