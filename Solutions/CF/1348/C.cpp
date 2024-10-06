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

mt19937 rng;
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 500005
#define MOD 998244353LL


void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    if (s[0] == s[k-1]) {
        if (k == n || s[k] == s.back()) {
            cout << s[k-1] << string((n-k+(k-1))/k, s[k]) << '\n';
        }
        else {
            cout << s.substr(k-1) << '\n';
        }
    }
    else {
        cout << s[k-1] << '\n';
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
//        cout << "Case #" << no << ": ";
        solve();
    }
}