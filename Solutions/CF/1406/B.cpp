#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize ("trapv")
using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 300005
//#define MOD 998244353LL
#define MOD 1000000007LL

void solve() {
    vector<long long> pos, neg;
    int n; cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x >= 0) pos.pb(x);
        else neg.pb(x);
    }

    if (pos.size() == 0) {
        sort(neg.begin(), neg.end());
        reverse(neg.begin(), neg.end());
        long long ans = 1;
        for (int i = 0; i < 5; i++)
            ans *= neg[i];
        cout << ans << '\n';
        return;
    }

    sort(pos.begin(), pos.end());
    reverse(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    long long ans = ~INF;
    for (int sz = 0; sz <= 5; sz++) {
        if (sz > pos.size() || 5-sz > neg.size()) continue;
        long long cur = 1;
        for (int i = 0; i < sz; i++)
            cur *= pos[i];

        for (int i = 0; i < 5-sz; i++)
            cur *= neg[i];

        ans = max(ans, cur);
    }

    cout << ans << '\n';

}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
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