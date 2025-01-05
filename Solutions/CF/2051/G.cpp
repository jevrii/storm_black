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

inline constexpr const char* ANSI_GREEN = "\e[0;32m";

#define DEBUG 1
// #define cerr   \
//     if (DEBUG) \
//     cerr << ANSI_GREEN
// #define test cerr << "hi\n";

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

template<typename T>
T ceil_divide(T a, T b)
{
    assert(a >= 0);
    assert(b > 0);
    return (a + b - 1) / b;
}

template<typename T, typename OutputStream>
void output_vector(const vector<T>& v, OutputStream& out)
{
    for (int i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i + 1 < v.size()) {
            cout << ' ';
        }
    }
    out << '\n';
}

inline bool test_bit(int bs, int pos) { return !!(bs & (1 << pos)); }

int dp[1 << 22][22];
int dist[25][25] = {};
int additional_dist[25] = {};
int n;
int cnt = 0;

void solve()
{
    vector<pair<int, char>> qs;
    int q;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        int x;
        char c;
        cin >> x >> c;
        --x;
        qs.push_back({x, c});
    }
    for (auto [id, c] : qs) {
        if (c == '+') {
            ++additional_dist[id];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            pii p1 = {0, 0};
            pii p2 = {1, 1};
            int d = 1;

            for (auto [id, c] : qs) {
                if (id == i) {
                    if (c == '+') {
                        p1.se++;
                    } else {
                        p1.fi++;
                    }
                }
                if (id == j) {
                    if (c == '+') {
                        p2.se++;
                    } else {
                        p2.fi++;
                    }
                }

                if (p1.se >= p2.fi) {
                    int need_d = p1.se + 1 - p2.fi;
                    d += need_d;
                    p2.fi += need_d;
                    p2.se += need_d;
                }
            }

            dist[i][j] = d;
        }
    }

    memset(dp, INF, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[(1 << i)][i] = 0;
    }

    for (int bs = 1; bs < (1 << n); ++bs) {
        for (int last = 0; last < n; ++last) {
            if (!test_bit(bs, last)) {
                continue;
            }
            for (int nxt = 0; nxt < n; ++nxt) {
                if (!test_bit(bs, nxt)) {
                    auto& next_dp = dp[bs | (1 << nxt)][nxt];
                    next_dp = min(next_dp, dp[bs][last] + dist[last][nxt]);
                }
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i] + additional_dist[i]);
    }
    cout << ans + 1 << '\n';

    // vector<int> ord(n);
    // iota(ord.begin(), ord.end(), 0);
    // do {
    //     for (int x : ord) {
    //         cerr << x << ",";
    //     }
    //     cerr << " ";
    //     int ans = 1;
    //     cerr << ans << ";";
    //     for (int i = 0; i + 1 < n; i++) {
    //         ans += dist[ord[i]][ord[i + 1]];
    //         cerr << ans << ";";
    //     }
    //     ans += additional_dist[ord.back()];
    //     cerr << ans << '\n';
    // } while (next_permutation(ord.begin(), ord.end()));
}

int main()
{
#ifdef LOCAL
    auto start_time = clock();
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

#ifndef INTERACTIVE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

#ifdef LOCAL
    static const auto run_with_stack_size = [](void (*func)(void), size_t stsize) {
        char *stack, *send;
        stack = (char*)malloc(stsize);
        send = stack + stsize - 16;
        send = (char*)((uintptr_t)send / 16 * 16);
        asm volatile("mov %%rsp, (%0)\n"
                     "mov %0, %%rsp\n"
                     :
                     : "r"(send));
        func();
        asm volatile("mov (%0), %%rsp\n" : : "r"(send));
        free(stack);
    };
#endif

    int t = 1;
    // cin >> t;
    for (int no = 1; no <= t; no++) {
        // cout << "Case #" << no << ": ";
#ifdef LOCAL
        // run with 1GB stack
        run_with_stack_size(solve, static_cast<size_t>(1) * 1024 * 1024 * 1024);
#else
        solve();
#endif
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}
