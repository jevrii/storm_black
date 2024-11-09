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

void solve() {}

int main()
{
#ifdef LOCAL
    auto start_time = clock();
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
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
    // cin >> t;
    for (int no = 1; no <= t; no++) {
        // cout << "Case #" << no << ": ";
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
