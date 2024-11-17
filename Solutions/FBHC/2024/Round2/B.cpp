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

inline constexpr int ROW_COUNT = 6;
inline constexpr int COL_COUNT = 7;
inline constexpr int WIN_LEN = 4;

using board_state_t = std::array<int, COL_COUNT>;
using board_state_hash_t = uint32_t;

class solver {
private:
    using player_id_t = char;

    class flags_t {
    public:
        void set(player_id_t p)
        {
            if (p == 'C') {
                bs_ |= 1;
            } else if (p == 'F') {
                bs_ |= (1 << 1);
            } else {
                assert(0);
            }
        }

        bool test(player_id_t p) const
        {
            int b = 1;
            if (p == 'F') {
                b <<= 1;
            }
            return (!!(bs_ & b));
        }

        void combine(const flags_t& other) { bs_ |= other.bs_; }

    private:
        uint8_t bs_ = 0;
    };

public:
    void input()
    {
        vector<string> v(ROW_COUNT);
        for (int i = ROW_COUNT - 1; i >= 0; --i) {
            cin >> v[i];
        }
        for (int i = 0; i < ROW_COUNT; i++) {
            for (int j = 0; j < COL_COUNT; j++) {
                full_grid_[i][j] = v[i][j];
            }
        }
    }

    void solve()
    {
        board_state_t empty_state{};
        auto f = find_winner(empty_state);

        string out;
        if (f.test('C')) {
            out.push_back('C');
        }
        if (f.test('F')) {
            out.push_back('F');
        }
        if (out.size() == 2) {
            cout << "?\n";
        } else if (out.empty()) {
            cout << "0\n";
        } else {
            cout << out << "\n";
        }
    }

private:
    static player_id_t query_next_player(const board_state_t& state)
    {
        int sum = accumulate(state.begin(), state.end(), 0);
        return ((sum % 2 == 0) ? 'C' : 'F');
    }

    bool cause_win(const board_state_t& state, const int inc_col_idx) const
    {
        static constexpr int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        static constexpr int dc[] = {1, 0, -1, 1, -1, 1, 0, -1};

        for (int d = 0; d < 8; ++d) {
            int cr = state[inc_col_idx];
            int cc = inc_col_idx;

            auto is_valid = [&inc_col_idx, &state](int r, int c) {
                if ((r < 0) || (r >= ROW_COUNT)) {
                    return false;
                }
                if ((c < 0) || (c >= COL_COUNT)) {
                    return false;
                }
                if (c == inc_col_idx) {
                    return r <= state[inc_col_idx];
                }
                return r < state[c];
            };

            deque<player_id_t> q;
            q.push_back(full_grid_[cr][cc]);
            while (true) {
                cr += dr[d];
                cc += dc[d];
                if (!is_valid(cr, cc)) {
                    break;
                }
                q.push_back(full_grid_[cr][cc]);
            }
            cr = state[inc_col_idx];
            cc = inc_col_idx;
            while (true) {
                cr -= dr[d];
                cc -= dc[d];
                if (!is_valid(cr, cc)) {
                    break;
                }
                q.push_front(full_grid_[cr][cc]);
            }

            for (int i = 0; i + WIN_LEN <= q.size(); i++) {
                if (count(q.begin() + i, q.begin() + i + WIN_LEN,
                        full_grid_[state[inc_col_idx]][inc_col_idx])
                    == WIN_LEN) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    flags_t find_winner(const board_state_t& state)
    {
        auto& ans = dp_winner_[hash_state(state)];
        if (ans) {
            return *ans;
        }
        // skip visited
        flags_t flags;
        player_id_t next_player = query_next_player(state);
        for (int i = 0; i < COL_COUNT; i++) {
            if (state[i] >= ROW_COUNT) {
                continue;
            }
            if (full_grid_[state[i]][i] == next_player) {
                auto next_state = state;
                ++next_state[i];
                if (!can_finish(next_state)) {
                    continue;
                }
                if (cause_win(state, i)) {
                    flags.set(next_player);
                } else {
                    auto f = find_winner((next_state));
                    flags.combine(f);
                }
            }
        }
        ans = flags;

        return flags;
    }

    bool can_finish(const board_state_t& state)
    {
        auto& ans = dp_can_finish_[hash_state(state)];
        if (ans) {
            return *ans;
        }
        // skip visited
        bool is_full = (count(state.begin(), state.end(), ROW_COUNT) == COL_COUNT);
        if (is_full) {
            ans = true;
            return true;
        }

        bool ret = false;

        player_id_t next_player = query_next_player(state);
        for (int i = 0; i < COL_COUNT; i++) {
            if (state[i] >= ROW_COUNT) {
                continue;
            }
            if (full_grid_[state[i]][i] == next_player) {
                auto next_state = state;
                ++next_state[i];
                ret |= can_finish(next_state);
            }
        }

        ans = ret;
        return ret;
    }

    static int hash_state(const board_state_t& state)
    {
        int idx = 0;
        for (int i = 0; i < COL_COUNT; i++) {
            idx *= ROW_COUNT + 1;
            idx += state[i];
        }
        return idx;
    }

private:
    std::array<std::array<player_id_t, COL_COUNT>, ROW_COUNT> full_grid_;

    static constexpr size_t TOTAL_STATE_COUNT = 7 * 7 * 7 * 7 * 7 * 7 * 7;
    std::optional<flags_t> dp_winner_[TOTAL_STATE_COUNT];
    std::optional<bool> dp_can_finish_[TOTAL_STATE_COUNT];
};

void solve()
{
    solver s;
    s.input();
    s.solve();
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
    cin >> t;
    for (int no = 1; no <= t; no++) {
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
