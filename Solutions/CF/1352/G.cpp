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
#define MAXN 500005
#define MOD 998244353LL

int n;

void solve() {

    cin >> n;

    if (n == 2) cout << -1 << '\n';
    else if (n == 3) cout << -1 << '\n';
    else if (n == 4) cout << "2 4 1 3" << '\n';
    else {
        int k;
        for (k = 1; k+7 < n; k += 4) {
            cout << k+1 << ' ' << k+3 << ' ' << k << ' ' << k+2 << ' ';
        }
        if (n%4 == 1) cout << k+1 << ' ' << k+3 << ' ' << k << ' ' << k+2 << ' ' << n << '\n';
        if (n%4 == 2) cout << k << ' ' << k+3 << ' ' << k+1 << ' ' << k+4 << ' ' << k+2 << ' ' << k+5 << '\n';
        if (n%4 == 3) cout << k+1 << ' ' << k+3 << ' ' << k+6 << ' ' << k+4 << ' ' << k << ' ' << k+2 << ' ' << k+5 << '\n';
        if (n%4 == 0) cout << k+1 << ' ' << k+3 << ' ' << k << ' ' << k+2 << ' ' << k+5 << ' ' << k+7 << ' ' << k+4 << ' ' << k+6 << '\n';
//        if (n%4 == 0) cout << '\n';
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