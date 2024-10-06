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
    int a, b, c;
    cin >> a >> b >> c;

    string s;

    if (b) {

        for (int i = 0; i < b+1; i++) {
            s += string(1, '0'+i%2);
            if (i == 0) {
                s += string(a, '0');
            }
            if (i == 1) {
                s += string(c, '1');
            }
        }

    }
    else {
        if (a) s += string(a+1, '0');
        else s += string(c+1, '1');
    }

    cout << s << '\n';



    // 0010111111
    // 1110011110

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