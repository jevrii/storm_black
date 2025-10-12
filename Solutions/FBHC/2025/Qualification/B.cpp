#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

class custom_err_ostream {
public:
    template<typename T>
    custom_err_ostream& operator<<([[maybe_unused]] const T& obj)
    {
#ifdef LOCAL
        static constexpr const char* ANSI_GREEN = "\e[0;32m";
        static constexpr const char* ANSI_RESET = "\e[0m";
        cerr << ANSI_GREEN << obj << ANSI_RESET;
#endif
        return *this;
    }
};

custom_err_ostream jerr;

// #define test jerr << "hi\n";

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

void solve()
{
    int r, c, s;
    cin >> r >> c >> s;
    vector<string> a(r);
    for (auto& s : a) {
        cin >> s;
    }

    vector<vector<bool>> g(r, vector<bool>(c));

    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, 1, -1, 0};

    {
        vector<vector<int>> dis(r, vector<int>(c, INF));
        vector<vector<bool>> vis(r, vector<bool>(c));

        queue<pii> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (a[i][j] == '#') {
                    q.push({i, j});
                }
            }
        }

        auto is_valid = [&](int x, int y) {
            if (x < 0 || x >= r || y < 0 || y >= c) {
                return false;
            }
            if (a[x][y] == '#') {
                return false;
            }
            return true;
        };

        for (int i = 0; i < r; i++) {
            q.push({i, -1});
            q.push({i, c});
        }
        for (int i = 0; i < c; i++) {
            q.push({-1, i});
            q.push({r, i});
        }

        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = t.fi + dx[i];
                int ny = t.se + dy[i];
                if (!is_valid(nx, ny)) {
                    continue;
                }
                if (vis[nx][ny]) {
                    continue;
                }

                vis[nx][ny] = 1;
                if (is_valid(t.fi, t.se)) {
                    dis[nx][ny] = dis[t.fi][t.se] + 1;
                } else {
                    dis[nx][ny] = 1;
                }
                q.push({nx, ny});
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                g[i][j] = (vis[i][j] && dis[i][j] > s);
            }
        }
    }

    vector<vector<bool>> vis(r, vector<bool>(c));
    int ans = 0;
    int vis_cnt = 0;

    auto start_bfs = [&](int x, int y) {
        queue<pii> q;
        assert(!vis[x][y]);
        ++vis_cnt;
        vis[x][y] = 1;
        q.push({x, y});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = t.fi + dx[i];
                int ny = t.se + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                    continue;
                }
                if (!g[nx][ny]) {
                    continue;
                }
                if (!vis[nx][ny]) {
                    ++vis_cnt;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    };

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (g[i][j] && !vis[i][j]) {
                int old_cnt = vis_cnt;
                start_bfs(i, j);
                ans = max(ans, vis_cnt - old_cnt);
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
#ifdef LOCAL
    auto start_time = clock();
    freopen("zone_in_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
    cin >> t;
    for (int no = 1; no <= t; no++) {
        cout << "Case #" << no << ": ";
#ifdef LOCAL
        // run with 1GB stack
        run_with_stack_size(solve, static_cast<size_t>(1) * 1024 * 1024 * 1024);
        // solve();
#else
        solve();
#endif
    }

#ifdef LOCAL
    jerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}
