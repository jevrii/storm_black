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

pair<string, int> a[1000];

bool run(int &acc) {
    vector<bool> vis(1000);
    int pos = 0;
    while (not vis[pos]) {
        vis[pos] = 1;
        if (a[pos].fi == "jmp") pos += a[pos].se;
        else if (a[pos].fi == "acc") acc += a[pos].se, pos++;
        else if (a[pos].fi == "nop") pos++;
        else if (pos == 649) break;
    }
    return pos == 649;
}

void solve() {
    for (int i = 0; i < 649; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 0; i < 649; i++) {
        int acc = 0;
        if (a[i].fi == "nop") {
            a[i].fi = "jmp";
            bool status = run(acc);
            if (status) {
                cout << acc << '\n';
                return;
            } else
                a[i].fi = "nop";
        }

        if (a[i].fi == "jmp") {
            a[i].fi = "nop";
            bool status = run(acc);
            if (status) {
                cout << acc << '\n';
                return;
            } else
                a[i].fi = "jmp";
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