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
#define INF 0x3f3f3f3f
//#define MOD 998244353LL
#define MOD 1000000007LL

char a[1005][1005];
int f[255];

void solve() {
    int n, l, k;
    cin >> n >> l >> k;
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    int cur = 0;
    int st = 0;

    for (int pos = 0; pos < l; pos++) {
        for (int id = st; id < k; id++) {
            a[id][pos] = s[cur];
            cur++;
            if (id-1 >= 0 && a[id][pos] != a[id-1][pos]) {
                st = id;
            }
        }
    }

    for (int i = 0; i < l; i++)
        cout << a[k-1][i];

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
//        cout << "Case " << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}