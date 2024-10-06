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

//mt19937 rng;
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 500005
#define MOD 998244353LL


void solve() {
    map<char, int> m;
//    int u;
//    cin >> u;
    for (int i = 0; i < 10000; i++) {
        long long mx = rand(1, 10000000000000000LL);
        long long res = rand(1, mx);
        string s = to_string(res);
        m[s[0]]++;
    }
//
    for (auto op : m) {
        cout << op.fi << ' ' << op.se << '\n';
    }




}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    for (int no = 1; no <= t; no++) {
        cout << "Case #" << no << ": ";
        solve();
    }
}