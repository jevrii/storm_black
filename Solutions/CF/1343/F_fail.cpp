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

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 500005
#define MOD 998244353LL

bitset<205> contained[205];
bool done[205];
int n;
vector<int> buckets[205];
bool pp[205][205];

bool work(int last) {
    vector<int> ans;
    ans.pb(last);

    memset(done, 0, sizeof(done));
    for (int i = 2; i <= n; i++)
        for (int x : buckets[i])
            contained[x][i] = 1;

    done[last] = 1;

    for (int i = 2; i < n-1; i++) {
        int id = contained[last]._Find_first();
        int nxt = -1;
        for (int x : buckets[id]) {
            contained[x][id] = 0;
            if (contained[x].count() == 1) {
                nxt = x;
            }
        }
        last = nxt;
        if (last == -1) return 0;
        done[last] = 1;
        ans.pb(last);
    }

    int x = -1, y = -1;
    for (int i = 1; i <= n; i++) {
        if (x == -1 and not done[i]) x = i;
        else if (not done[i] and x != -1) y = i;
    }

    if (not pp[x][y]) {
        ans.pb(y);
        ans.pb(x);
    }
    else {
        ans.pb(x);
        ans.pb(y);
    }

    int pos[205];
    for (int i = 0; i < n; i++) {
        pos[ans[i]] = i;
    }
    for (int i = 2; i <= n; i++) {
        int hi = -1, lo = 999;
        for (int x : buckets[i]) {
            hi = max(hi, pos[x]);
            lo = min(lo, pos[x]);
        }
        if (hi-lo+1 != buckets[i].size()) {
            return 0;
        }
    }

    reverse(ans.begin(), ans.end());
    for (int x : ans) cout << x << ' ';
    cout << '\n';
    return 1;
}

void solve() {
    cin >> n;
    memset(pp, 0, sizeof(pp));
    for (int i = 1; i <= n; i++) {
        contained[i].reset();
        done[i] = 0;
        buckets[i].clear();
    }
    for (int i = 2; i <= n; i++) {
        int len; cin >> len;
        for (int j = 0, x; j < len; j++) {
            cin >> x;
            buckets[i].pb(x);
            contained[x][i] = 1;
        }
        for (int x : buckets[i])
            for (int y : buckets[i]) {
                if (x != y) {
                    pp[x][y] = 1;
                }
            }
    }

    if (n == 2) {
        cout << "1 2\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (contained[i].count() == 1) {
            if (work(i)) return;
        }
    }

    assert(0);
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