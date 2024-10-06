#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 2000006
#define MOD 998244353LL

int n, k;

void solve() {
    cin >> n >> k;
    bool have = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == k) have = 1;
        if (x >= k) v.pb(i);
    }

    if (not have) cout << "no\n";
    else {
        if (n == 1) {
            cout << "yes\n";
        }
        else {
            int ret = INF;
            for (int i = 0; i+1 < v.size(); i++)
                ret = min(ret, v[i+1]-v[i]);
            if (ret <= 2) cout << "yes\n";
            else cout << "no\n";
        }
    }



}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
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