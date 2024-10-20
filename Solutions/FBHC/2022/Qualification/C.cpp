#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#ifdef LOCAL
#pragma GCC optimize("trapv")
#endif

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define DEBUG 1
#define cerr   \
    if (DEBUG) \
    cerr
#define test cerr << "hi\n";

template<typename T>
T rand(T l, T r)
{
    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<long long>(l, r)(rng);
}

using namespace __gnu_pbds;

template<typename T>
using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

inline constexpr int MAXN = 1000006;
inline constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
// inline constexpr ll MOD = 998244353LL;
// inline constexpr ll MOD = 1000000007LL;

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    vector<string> v;

    for (int bs = 0; bs < (1 << 10); bs++) {
        if (v.size() == n - 1) {
            break;
        }
        string t;
        for (int i = 0; i < 10; i++) {
            if (bs & (1 << i)) {
                t.push_back('.');
            } else {
                t.push_back('-');
            }
        }
        if (s.size() > 10) {
            if (s.substr(0, t.size()) == t) {
                continue;
            }
            v.push_back(t);
        } else {
            if (t.substr(0, s.size()) == s) {
                continue;
            }
            v.push_back(t);
        }
    }
    cout << '\n';
    for (string t : v) {
        cout << t << '\n';
    }
}

int main()
{
#ifdef LOCAL
    auto start_time = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifndef INTERACIVE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    int t = 1;
    cin >> t;
    for (int no = 1; no <= t; no++) {
        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "\e[0;32m"
         << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}
