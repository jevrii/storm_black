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

void verify(vector<int> a, vector<int> b, vector<pii> ops)
{
    for (auto op : ops) {
        int mx = max(a[op.fi], a[op.se]);
        a[op.fi] = a[op.se] = mx;
    }
    assert(a == b);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x : a) {
        cin >> x;
    }
    for (int& x : b) {
        cin >> x;
    }
    const vector<int> ca = a;
    const vector<int> cb = b;

    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            cout << -1 << '\n';
            return;
        }
    }

    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (!m.contains(b[i])) {
            cout << -1 << '\n';
            return;
        }
    }

    vector<pii> ops;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            ops.push_back({i, m[b[i]]});
        }
    }

    sort(ops.begin(), ops.end(),
        [&](const auto& lhs, const auto& rhs) { return a[lhs.se] < a[rhs.se]; });

    verify(ca, cb, ops);

    cout << ops.size() << '\n';
    for (auto op : ops) {
        cout << op.fi + 1 << ' ' << op.se + 1 << '\n';
    }
}

int main()
{
#ifdef LOCAL
    auto start_time = clock();
    freopen("warm_up_input.txt", "r", stdin);
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
