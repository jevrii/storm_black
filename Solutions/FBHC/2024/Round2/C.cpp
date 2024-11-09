#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#ifdef LOCAL
// #pragma GCC optimize("trapv")
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
#define cerr   \
    if (DEBUG) \
    cerr << ANSI_GREEN
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
    int r, c;
    ll k;
    cin >> r >> c >> k;
    cerr << r << ' ' << c << '\n';

    vector<vector<int>> a(r, vector<int>(c));

    map<int, vector<pii>> key_to_pos;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
            key_to_pos[a[i][j]].push_back({i, j});
        }
    }

    vector<vector<int>> ps_row(r, vector<int>(c + 1));
    vector<vector<int>> ps_col(c, vector<int>(r + 1));

    auto add = [&](const pii& pos, int val) {
        for (int i = pos.se + 1; i < ps_row[pos.fi].size(); i++) {
            ps_row[pos.fi][i] += val;
        }
        for (int i = pos.fi + 1; i < ps_col[pos.se].size(); i++) {
            ps_col[pos.se][i] += val;
        }
    };

    auto query_row = [&](int row, int lo, int hi) {
        if (row < 0 || row >= r) {
            return 0;
        }
        lo = max(0, lo);
        hi = min(c - 1, hi);
        assert(hi >= lo);

        auto& ps = ps_row[row];
        return (hi - lo + 1) - (ps[hi + 1] - ps[lo]);
    };

    auto query_col = [&](int col, int lo, int hi) {
        if (col < 0 || col >= c) {
            return 0;
        }
        lo = max(0, lo);
        hi = min(r - 1, hi);
        assert(hi >= lo);

        auto& ps = ps_col[col];
        return (hi - lo + 1) - (ps[hi + 1] - ps[lo]);
    };

    vector<ll> hops_by_dist(805);

    for (const auto& [key, pos_list] : key_to_pos) {
        for (const auto& pos : pos_list) {
            add(pos, +1);
        }
        for (const auto& pos : pos_list) {
            for (int d = 1; d <= 800; ++d) {
                // [pos.fi - d, pos.fi + d]
                // [pos.se - d, pos.se + d]

                int lr = pos.fi - d;
                int hr = pos.fi + d;
                int lc = pos.se - d;
                int hc = pos.se + d;

                hops_by_dist[d] += query_row(lr, lc + 1, hc - 1);
                hops_by_dist[d] += query_row(hr, lc + 1, hc - 1);
                hops_by_dist[d] += query_col(lc, lr, hr);
                hops_by_dist[d] += query_col(hc, lr, hr);
            }
        }
        for (const auto& pos : pos_list) {
            add(pos, -1);
        }

        // for (auto o : ps_row) {
        //     assert(count(o.begin(), o.end(), 0) == o.size());
        // }
        // for (auto o : ps_col) {
        //     assert(count(o.begin(), o.end(), 0) == o.size());
        // }
    }

    // {
    //     vector<ll> hops_by_dist_brute(805);
    //     for (int i = 0; i < r; i++) {
    //         for (int j = 0; j < c; j++) {
    //             for (int i2 = 0; i2 < r; i2++) {
    //                 for (int j2 = 0; j2 < c; j2++) {
    //                     if (a[i][j] != a[i2][j2]) {
    //                         int d = max(abs(i2 - i), abs(j2 - j));
    //                         hops_by_dist_brute[d]++;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     assert(hops_by_dist_brute == hops_by_dist);
    // }

    ll cur = 0;
    for (int i = 1; i < 805; i++) {
        if (cur + hops_by_dist[i] >= k) {
            cout << i << '\n';
            return;
        }
        cur += hops_by_dist[i];
    }
}

int main()
{
#ifdef LOCAL
    auto start_time = clock();
    freopen("bunny_hopscotch_input.txt", "r", stdin);
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifndef INTERACIVE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

#ifdef LOCAL
    static const auto run_with_stack_size = [](void (*func)(), size_t stsize) {
        char* stack = (char*)malloc(stsize);
        char* send = stack + stsize - 16;
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
    cin >> t;
    for (int no = 1; no <= t; no++) {
        cerr << no << '\n';
        cout << "Case #" << no << ": ";
#ifdef LOCAL
        // run with 16GB stack
        run_with_stack_size(solve, static_cast<size_t>(16) * 1024 * 1024 * 1024);
#else
        solve();
#endif
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}
