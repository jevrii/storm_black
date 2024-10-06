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

void solve() {

    int n, k;
    cin >> n >> k;

    if (2*k <= n && (n-2*k)%2 == 0) {
        cout << "YES\n";
        for (int i = 0; i < k-1; i++) {
            cout << 2 << ' ';
            n -= 2;
        }
        cout << n << '\n';
    }
    else if (1*k <= n && (n-1*k)%2 == 0){
        cout << "YES\n";
        for (int i = 0; i < k-1; i++) {
            cout << 1 << ' ';
            n -= 1;
        }
        cout << n << '\n';
    }
    else {
        cout << "NO\n";
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