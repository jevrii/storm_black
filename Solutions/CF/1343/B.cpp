#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

#define DEBUG 0
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 500005
#define MOD 998244353LL

void solve() {
    int n;
    cin >> n;

    if ((n/2) % 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    for (int i = 1; i <= n/2; i++)
        cout << i*2 << ' ';
    for (int i = 0; i < n/2; i++) {
        if (i+1 == n/2) {
            cout << i*2+1+n/2 << ' ';
        }
        else cout << i*2+1 << ' ';
    }

    cout << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }
}