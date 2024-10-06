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
    map<char, int> m;
    int u;
    cin >> u;

    bool can[255][10], can_first[255];
    memset(can, 1, sizeof(can));
    memset(can_first, 0, sizeof(can_first));

    set<int> cc;

    for (int i = 0; i < 10000; i++) {
        string x, r;
        cin >> x >> r;
        if (x.length() == r.length()) {
            for (int i = x[0]+1-'0'; i <= 9; i++) {
                can[r[0]][i] = 0;
            }
            can_first[r[0]] = 1;
        }
        for (char c : r) cc.insert(c);
    }

    string ans(cc.begin(), cc.end());

    sort(ans.begin(), ans.end());

    do {
        bool bad = 0;
        for (int i = 0; i < 10; i++) {
            if (not can[ans[i]][i]) {
                bad = 1;
                break;
            }
        }
        if (can_first[ans[0]]) bad = 1;
        if (not bad) {
            cout << ans << '\n';
            return;
        }
    } while (next_permutation(ans.begin(), ans.end()));
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