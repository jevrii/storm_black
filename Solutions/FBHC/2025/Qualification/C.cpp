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
    int n;
    cin >> n;
    vector<int> b(n);
    for (int& x : b) {
        cin >> x;
    }

    {
        if (n == 1) {
            cout << "1" << '\n';
            cout << "1 1" << '\n';
            return;
        }
    }

    vector<pii> v;
    b.push_back(-1);

    int start_idx = 0;
    for (int i = 1; i < b.size(); i++) {
        if (b[start_idx] == 1) {
            if (b[i] == b[i - 1] + 1) {
                // 1 2 3 4 **5**
                continue;
            } else {
                // 1 2 3 4 5 **2**
                // 1 2 3 4 5 **7**
                // 1 2 3 4 5 **1**
                v.push_back({i - start_idx, 0});
                start_idx = i;
            }
        } else {
            if (b[i] == b[start_idx] - 1) {
                v.push_back({i - start_idx + 1, b[start_idx] - 1});
                start_idx = i + 1;
                ++i;
            }
        }
    }
    vector<int> rots(v.size());

    int total_rots = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        // (total_rots + x) % len == offset
        //
        int len = v[i].first;
        int offset = v[i].second;
        int x = ((offset - total_rots) % len + len) % len;
        rots[i] = x;
        total_rots += x;
    }

    cout << v.size() + std::accumulate(rots.begin(), rots.end(), 0) << '\n';

    for (int i = 0; i < v.size(); ++i) {
        cout << 1 << ' ' << v[i].first << '\n';
        for (int j = 0; j < rots[i]; ++j) {
            cout << 2 << '\n';
        }
    }
}

int main()
{
#ifdef LOCAL
    auto start_time = clock();
    freopen("monkey_around_input.txt", "r", stdin);
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
        // run_with_stack_size(solve, static_cast<size_t>(1) * 1024 * 1024 * 1024);
        solve();
#else
        solve();
#endif
    }

#ifdef LOCAL
    jerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}
