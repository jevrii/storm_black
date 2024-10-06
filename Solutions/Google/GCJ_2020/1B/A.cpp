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

int on[40][2];
long long x, y;
bool flip_x, flip_y;

void solve() {
    cin >> x >> y;
    flip_x = x<0;
    flip_y = y<0;

    int mx = 0;

    for (int i = 0; i <= 30; i++) {
        on[i][0] = !!(x & (1LL << i));
        on[i][1] = !!(y & (1LL << i));

        if (on[i][0] or on[i][1]) {
            mx = i;
        }
    }

    for (int i = 0; i <= 30; i++) {
        if (on[i][0] and on[i][1]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    if (not (on[0][0] or on[0][1])) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    string ans;
    int prev_pos, prev_str;

    for (int i = 0; i <= mx; i++) {
        if (on[i][0]) {
            prev_pos = i;
            prev_str = 0;
            ans.pb("EW"[flip_x]);
        }
        else if (on[i][1]) {
            prev_pos = i;
            prev_str = 1;
            ans.pb("NS"[flip_y]);
        }
        else {
            if (prev_str == 0) {
                ans.pb("EW"[flip_x]);
                ans[prev_pos] = "EW"[flip_x^1];
            }
            else {
                ans.pb("NS"[flip_y]);
                ans[prev_pos] = "NS"[flip_y^1];
            }
            prev_pos = i;
        }
    }

    cout << ans << '\n';
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
        cout << "Case #" << no << ": ";
        solve();
    }
}