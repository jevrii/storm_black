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

#define MAXN 200005
#define INF 0x3f3f3f3f
//#define MOD 998244353LL
#define MOD 1000000007LL

int suf[MAXN];

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length();

    suf[n] = 0;

    for (int i = n-1; i >= 0; i--) {
        suf[i] = suf[i+1] + (s[i] != t[i]);
    }

    string ans;
    int ma = 0, mb = 0;
    for (int i = 0; i < n; i++) {
        set<char> ss;
        ss.insert('a');
        ss.insert('b');
        ss.insert('c');
        ss.insert(s[i]);
        ss.insert(t[i]);

        for (char c : ss) {
            int mma = ma, mmb = mb;
            if (c == s[i]) mma++;
            if (c == t[i]) mmb++;

            if (abs(mma - mmb) <= suf[i+1]) {
                ma = mma;
                mb = mmb;
                ans.pb(c);
                break;
            }
        }
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
        cout << "Case " << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}