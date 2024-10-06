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
#define MAXN 200005
#define MOD 998244353LL

char a[35][35];
int r, c;
bool done[255];

bool stable(char x) {
    bool bad = 0;
    for (int i = 1; i < r; i++)
        for (int j = 1; j <= c; j++) {
            if (a[i][j] == x && not (a[i+1][j] == x or done[a[i+1][j]])) {
                bad = 1;
                goto end;
            }
        }
    end:;
    return not bad;
}

void solve() {
    cin >> r >> c;
    memset(done, 0, sizeof(done));
    set<char> cc;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
            cc.insert(a[i][j]);
        }
    }

    string ans;

    for (int iter = 0; iter < cc.size(); iter++) {
        for (char c : cc) {
            if (done[c]) continue;
            if (stable(c)) {
                done[c] = 1;
                cerr << "stable " << c << '\n';
                ans += string(1, c);
            }
        }
    }

    if (count(done, done+255, 1) == cc.size()) {
        cout << ans << '\n';
    }
    else cout << -1 << '\n';

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
        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}