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
inline constexpr ll MOD = 998244353LL;
// inline constexpr ll MOD = 1000000007LL;

ll find_max(string s)
{
    int n = s.size();
    vector<ll> dp(n, INF);
    dp[0] = 1;

    auto get_dp = [&](int idx) -> ll {
        if (idx < 0) {
            return 1;
        }
        return dp[idx];
    };

    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            // x0, must be 10 or 20
            if ((s[i - 1] == '1') || (s[i - 1] == '2')) {
                dp[i] = get_dp(i - 2);
            } else {
                dp[i] = 0;
            }
        } else if (s[i - 1] == '0') {
            // x01, x02, x03... -> x0 3
            dp[i] = get_dp(i - 1);
        } else if ((s[i - 1] == '1')) {
            // x1y -> x 1y , x 1 y
            dp[i] = (get_dp(i - 2) + get_dp(i - 1)) % MOD;
        } else if ((s[i - 1] == '2') && (s[i] <= '6')) {
            // x26 -> x 26 , x 2 6
            dp[i] = (get_dp(i - 2) + get_dp(i - 1)) % MOD;
        } else {
            // x91, x81
            dp[i] = get_dp(i - 1);
        }
    }
    return dp[n - 1];
}

void brute(string s, int k)
{
    int cnt = count(s.begin(), s.end(), '?');
    int mx = 1;
    for (int i = 0; i < cnt; i++) {
        mx *= 10;
    }

    int n = s.size();

    vector<pair<int, string>> v;

    for (int combo = 0; combo < mx; combo++) {
        string s_cp = s;
        int get_cur_dig = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s_cp[i] == '?') {
                s_cp[i] = '0' + (combo % (get_cur_dig * 10)) / get_cur_dig;
                get_cur_dig *= 10;
            }
        }
        v.push_back({find_max(s_cp), s_cp});
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    cout << "brute " << v[k - 1].second << ' ' << v[k - 1].first << '\n';
}

void solve()
{
    string s;
    int k;
    cin >> s >> k;
    // brute(s, k);

    --k;
    int n = s.size();

    vector<int> v;
    bool ended = true;
    for (int i = n - 1; i >= 0; i--) {
        // x?0 -> x10, x20
        if (s[i] != '?') {
            continue;
        }
        bool ended = false;
        if (i == n - 1) {
            ended = true;
        } else if (i + 2 < n && s[i + 2] == '0') {
            // x?y0 -> ? x? y0  /  x ? yo
            ended = true;
        }
        if (ended) {
            if (i >= 1) {
                if (s[i - 1] == '?') {
                    v.push_back(9 + 6);
                    --i;
                } else if (s[i - 1] == '1') {
                    // 1? -> 11 to 19
                    v.push_back(9);
                } else if (s[i - 1] == '2') {
                    // 2? -> 21 to 26
                    v.push_back(6);
                } else {
                    // 3? -> 3 1 to 3 9
                    v.push_back(9);
                }
            } else {
                v.push_back(9);
            }
            ended = false;
        } else {
            if ((i + 1 < n) && (s[i + 1] == '0')) {
                // ?0 -> 10, 20
                v.push_back(2);
            } else if ((i + 1 < n) && (s[i + 1] >= '7') && (s[i + 1] <= '9')) {
                // ?7 -> 17
                v.push_back(1);
            } else {
                // ?6 -> 16, 26
                v.push_back(2);
            }
        }
    }

    auto transform_15 = [](int x) -> string {
        assert(x <= 14);
        if (x < 9) {
            return to_string(11 + x);
        }
        return to_string(21 + x - 9);
    };

    stack<char> st;
    for (auto it = v.begin(); it != v.end(); ++it) {
        int x = *it;

        int res = x - 1 - k % x;
        k /= x;
        if (x == 15) {
            string o = transform_15(res);
            st.push(o[1]);
            st.push(o[0]);
        } else {
            st.push('1' + res);
        }
    }

    for (char& c : s) {
        if (c == '?') {
            assert(!st.empty());
            c = st.top();
            st.pop();
        }
    }
    assert(st.empty());

    cout << s << ' ' << find_max(s) << '\n';
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
