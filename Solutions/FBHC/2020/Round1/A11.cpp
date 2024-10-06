#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
#define MAXN 1000006
//#define MOD 998244353LL
#define MOD 1000000007LL

int n;
long long l[MAXN], h[MAXN], w;
long long p[MAXN];

void get_input() {
    int k;
    long long a, b, c, d;
    cin >> n >> k >> w;

    for (int i = 1; i <= k; i++)
        cin >> l[i];
    cin >> a >> b >> c >> d;
    for (int i = k+1; i <= n; i++)
        l[i] = (a*l[i-2]+b*l[i-1]+c) % d + 1;

    for (int i = 1; i <= k; i++)
        cin >> h[i];
    cin >> a >> b >> c >> d;
    for (int i = k+1; i <= n; i++)
        h[i] = (a*h[i-2]+b*h[i-1]+c) % d + 1;
}

void solve() {
    get_input();
//    for (int i = 1; i <= n; i++) cout << l[i] << ' '; cout << '\n';
//    for (int i = 1; i <= n; i++) cout << h[i] << ' '; cout << '\n';

    long long last_pos = ~INF;
    deque<pii> q;
    q.push_back(mp(0, 0));
    map<int, int> hh;

    for (long long i = 1; i <= n; i++) {
        if (last_pos + w < l[i]) {
//            cerr << i << " new seg\n";
            p[i] = p[i-1] + h[i]*2+w*2;
        }
        else {
//            cerr << i << " height at " << hh[l[i]] << " continue\n";
            int cur_height = hh[l[i]];
            if (h[i] >= cur_height) {
                p[i] = p[i-1] + (w-(last_pos+w-l[i]))*2 + (h[i]-cur_height)*2;
            }
            else {
                p[i] = p[i-1] + (w-(last_pos+w-l[i]))*2;
            }
        }

        for (int j = 0; j <= w; j++)
            hh[l[i]+j] = max(hh[l[i]+j], (int) h[i]);

        last_pos = l[i];
    }

//    for (int i = 1; i <= n; i++) cout << p[i] << ' '; cout << '\n';

    long long ans = 1;
    for (int i = 1; i <= n; i++)
        (ans *= p[i]) %= MOD;
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