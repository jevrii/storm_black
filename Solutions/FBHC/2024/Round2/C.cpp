#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

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
// inline constexpr ll MOD = 998244353LL;
// inline constexpr ll MOD = 1000000007LL;

class test_instance {
public:
    int r, c;
    ll k;
    vector<vector<int>> a;
    map<int, vector<pii>> key_to_pos;

    void input()
    {
        cin >> r >> c >> k;

        a.resize(r);
        for (auto& row : a) {
            row.resize(c);
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> a[i][j];
                key_to_pos[a[i][j]].push_back({i, j});
            }
        }
    }

    void solve()
    {
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
            return ps[hi + 1] - ps[lo];
        };

        auto query_col = [&](int col, int lo, int hi) {
            if (col < 0 || col >= c) {
                return 0;
            }
            lo = max(0, lo);
            hi = min(r - 1, hi);
            assert(hi >= lo);

            auto& ps = ps_col[col];
            return ps[hi + 1] - ps[lo];
        };

        vector<ll> hops_by_dist(805);

        for (const auto& [key, pos_list] : key_to_pos) {
            for (const auto& pos : pos_list) {
                add(pos, +1);
            }

            vector<int> uniq_rows;
            vector<int> uniq_cols;
            for (const auto& pos : pos_list) {
                uniq_rows.push_back(pos.fi);
                uniq_cols.push_back(pos.se);
            }
            auto sort_and_uniq = [](vector<int>& v) {
                sort(v.begin(), v.end());
                auto it = unique(v.begin(), v.end());
                v.erase(it, v.end());
            };
            sort_and_uniq(uniq_rows);
            sort_and_uniq(uniq_cols);

            for (const auto& pos : pos_list) {
                bitset<850> done_dists;

                auto work_d = [&](int d) {
                    // [pos.fi - d, pos.fi + d]
                    // [pos.se - d, pos.se + d]

                    int lr = pos.fi - d;
                    int hr = pos.fi + d;
                    int lc = pos.se - d;
                    int hc = pos.se + d;

                    hops_by_dist[d] -= query_row(lr, lc + 1, hc - 1);
                    hops_by_dist[d] -= query_row(hr, lc + 1, hc - 1);
                    hops_by_dist[d] -= query_col(lc, lr, hr);
                    hops_by_dist[d] -= query_col(hc, lr, hr);
                };

                for (int r_idx : uniq_rows) {
                    int d = abs(pos.fi - r_idx);
                    if (d == 0) {
                        continue;
                    }
                    if (done_dists.test(d)) {
                        continue;
                    }
                    work_d(d);
                    done_dists.set(d);
                }

                for (int c_idx : uniq_cols) {
                    int d = abs(pos.se - c_idx);
                    if (d == 0) {
                        continue;
                    }
                    if (done_dists.test(d)) {
                        continue;
                    }
                    work_d(d);
                    done_dists.set(d);
                }
            }
            for (const auto& pos : pos_list) {
                add(pos, -1);
            }
        }

        for (int dr = -(r - 1); dr <= (r - 1); dr++) {
            for (int dc = -(c - 1); dc <= (c - 1); dc++) {
                if ((dr == 0) && (dc == 0)) {
                    continue;
                }
                int d = max(abs(dr), abs(dc));
                hops_by_dist[d] += (r - abs(dr)) * (c - abs(dc));
            }
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
                out << i << '\n';
                return;
            }
            cur += hops_by_dist[i];
        }
    }

public:
    ostringstream out;
};

int main()
{
#ifdef LOCAL
    auto start_time =
        duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    freopen("bunny_hopscotch_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifndef INTERACIVE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    int t = 1;
    cin >> t;
    vector<test_instance> instances(t + 1);
    vector<thread> threads(t + 1);

    cerr << fixed << setprecision(3);

    for (int tc = 1; tc <= t; tc++) {
        instances[tc].input();
        instances[tc].solve();
        // threads[tc].join();
        string output = instances[tc].out.str();
        cout << "Case #" << tc << ": " << output;

#ifdef LOCAL
        cerr << "\e[0;32m"
             << "TIME ELAPSED: test " << tc << ' '
             << double(duration_cast<chrono::milliseconds>(
                           chrono::system_clock::now().time_since_epoch())
                           .count()
                    - start_time)
                / 1000
             << '\n';
#endif

        cout << flush;
        assert(!output.empty());
    }
}
