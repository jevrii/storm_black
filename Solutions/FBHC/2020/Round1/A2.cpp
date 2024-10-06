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
long long l[MAXN], h[MAXN], w[MAXN];
long long p[MAXN];

void get_input() {
    int k;
    long long a, b, c, d;
    cin >> n >> k;

    for (int i = 1; i <= k; i++)
        cin >> l[i];
    cin >> a >> b >> c >> d;
    for (int i = k+1; i <= n; i++)
        l[i] = (a*l[i-2]+b*l[i-1]+c) % d + 1;

    for (int i = 1; i <= k; i++)
        cin >> w[i];
    cin >> a >> b >> c >> d;
    for (int i = k+1; i <= n; i++)
        w[i] = (a*w[i-2]+b*w[i-1]+c) % d + 1;

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
//    for (int i = 1; i <= n; i++) cout << w[i] << ' '; cout << '\n';

    set<pii> s;
    s.insert(mp(INF, ~INF)); // {ending point, starting point}

    for (long long i = 1; i <= n; i++) {
        auto it = s.lower_bound(mp(l[i], ~INF)); // segment that ends from l[i] from
        cerr << "---\niteration " << i << " {" << l[i] << ' ' << l[i]+w[i] << "}" << '\n';

        vector<pii> remove_list, insert_list;
        long long delta = 0;
        while (it != s.end() && it->se < l[i]+w[i]) {
            remove_list.pb(*it);
            int L, R; tie(R, L) = *it;
            cerr << "{" << L << ' ' << R << "}\n";
            if (l[i] <= L && R <= l[i]+w[i]) { // new seg completely cover others
                cerr << "case 1\n";
                delta += (R-L)*2-h[i]*2;
            }
            else if (l[i] <= L && l[i]+w[i] < R) {
                cerr << "case 2\n";
                delta += (l[i]+w[i]-L) * 2;
                insert_list.pb(mp(R, l[i]+w[i]));
            }
            else if (L < l[i] && R <= l[i]+w[i]) {
                cerr << "case 3\n";
                delta += (R-l[i]) * 2;
                insert_list.pb(mp(l[i], L));
            }
            else if (L < l[i] && l[i]+w[i] < R) {
                cerr << "case 4\n";
                delta += w[i]*2 + h[i]*2;
                insert_list.pb(mp(l[i], L));
                insert_list.pb(mp(R, l[i]+w[i]));
            }
            else {
                assert(0);
            }
            it++;
        }
//        cerr << delta << " xx\n";
        for (auto op : remove_list) {
//            cerr << "erase " << op.se << ' ' << op.fi << '\n';
            s.erase(op);
        }
        for (auto op : insert_list) {
//            cerr << "insert " << op.se << ' ' << op.fi << '\n';
            s.insert(op);
        }
        (p[i] = p[i-1] + delta) % MOD;
//        cerr << "p " << p[i] << '\n';
    }

//    for (int i = 1; i <= n; i++) cout << p[i] << ' '; cout << '\n';

    long long ans = 1;
    for (int i = 1; i <= n; i++)
        (ans *= p[i] % MOD) %= MOD;
    cout << ans << '\n';
}

int main() {
#ifdef LOCAL
    freopen("perimetric_chapter_2_input.txt", "r", stdin);
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