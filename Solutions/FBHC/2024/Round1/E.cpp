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

template<const int& MOD>
struct _m_int {
    int val;

    _m_int(int64_t v = 0)
    {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = int(v);
    }

    _m_int(uint64_t v)
    {
        if (v >= MOD)
            v %= MOD;
        val = int(v);
    }

    _m_int(int v)
        : _m_int(int64_t(v))
    {}
    _m_int(unsigned v)
        : _m_int(uint64_t(v))
    {}

    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }

    _m_int& operator+=(const _m_int& other)
    {
        val -= MOD - other.val;
        if (val < 0)
            val += MOD;
        return *this;
    }

    _m_int& operator-=(const _m_int& other)
    {
        val -= other.val;
        if (val < 0)
            val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD)
    {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n" : "=a"(quot), "=d"(rem) : "d"(x_high), "a"(x_low), "r"(m));
        return rem;
    }

    _m_int& operator*=(const _m_int& other)
    {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }

    _m_int& operator/=(const _m_int& other) { return *this *= other.inv(); }

    friend _m_int operator+(const _m_int& a, const _m_int& b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int& a, const _m_int& b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int& a, const _m_int& b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int& a, const _m_int& b) { return _m_int(a) /= b; }

    _m_int& operator++()
    {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    _m_int& operator--()
    {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    _m_int operator++(int)
    {
        _m_int before = *this;
        ++*this;
        return before;
    }
    _m_int operator--(int)
    {
        _m_int before = *this;
        --*this;
        return before;
    }

    _m_int operator-() const { return val == 0 ? 0 : MOD - val; }

    friend bool operator==(const _m_int& a, const _m_int& b) { return a.val == b.val; }
    friend bool operator!=(const _m_int& a, const _m_int& b) { return a.val != b.val; }
    friend bool operator<(const _m_int& a, const _m_int& b) { return a.val < b.val; }
    friend bool operator>(const _m_int& a, const _m_int& b) { return a.val > b.val; }
    friend bool operator<=(const _m_int& a, const _m_int& b) { return a.val <= b.val; }
    friend bool operator>=(const _m_int& a, const _m_int& b) { return a.val >= b.val; }

    static const int SAVE_INV = int(1e6) + 5;
    static _m_int save_inv[SAVE_INV];

    static void prepare_inv()
    {
        // Ensures that MOD is prime, which is necessary for the inverse algorithm below.
        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);

        save_inv[0] = 0;
        save_inv[1] = 1;

        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }

    _m_int inv() const
    {
        if (save_inv[1] == 0)
            prepare_inv();

        if (val < SAVE_INV)
            return save_inv[val];

        _m_int product = 1;
        int v = val;

        do {
            product *= MOD - MOD / v;
            v = MOD % v;
        } while (v >= SAVE_INV);

        return product * save_inv[v];
    }

    _m_int pow(int64_t p) const
    {
        if (p < 0)
            return inv().pow(-p);

        _m_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            p >>= 1;

            if (p > 0)
                a *= a;
        }

        return result;
    }

    friend ostream& operator<<(ostream& os, const _m_int& m) { return os << m.val; }
};

template<const int& MOD>
_m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];

const int MOD = 998244353;
using mod_int = _m_int<MOD>;

// int main()
// {
// #ifdef LOCAL
//     auto start_time = clock();
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//
// #ifndef INTERACIVE
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
// #endif
//
//     int t = 1;
//     cin >> t;
//     for (int no = 1; no <= t; no++) {
//         cerr << no << '\n';
//         cout << "Case #" << no << ": ";
//         solve();
//     }
//
// #ifdef LOCAL
//     cerr << "\e[0;32m"
//          << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
// #endif
// }

class test_instance {
public:
    int n;
    vector<string> v;
    int masks[30][105] = {0};

    void input()
    {
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v.push_back(s);
        }
    }

    void solve()
    {
        int n;
        vector<string> v;
        int masks[30][110] = {0};

        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        mod_int ans = 0;

        // vector<vector<int>> masks(128, vector<int>(105));
        for (int len = 0; len < 105; ++len) {
            auto fill_mask = [&](char c) {
                int mask = 0;
                for (int i = 0; i < n; i++) {
                    assert(i < v.size());
                    if (len >= v[i].size()) {
                        continue;
                    }
                    if (v[i][len] == c) {
                        mask |= (1 << i);
                    }
                }
                if (c == '?') {
                    masks[26][len] = mask;
                } else {
                    // cerr << (int)(c - 'A') << ' ' << len << ' ' << mask << '\n';
                    masks[c - 'A'][len] = mask;
                }
            };
            fill_mask('?');
            for (char c = 'A'; c <= 'Z'; ++c) {
                fill_mask(c);
            }
        }

        for (int bs = 1; bs < (1 << n); ++bs) {
            int sgn = 1;
            if (__builtin_popcount(bs) % 2 == 0) {
                sgn = -1;
            }

            mod_int cur_prefix = 1;
            mod_int cur_add = 1;

            int min_len = INF;
            for (int i = 0; i < n; i++) {
                if (!!((1 << i) & bs)) {
                    min_len = min(min_len, (int)v[i].size());
                }
            }

            auto get_mask = [&](char c, int len) -> int {
                assert(len < 105);
                if (c == '?') {
                    return masks[26][len];
                }
                return masks[c - 'A'][len];
            };

            for (int len = 0; len <= 105; ++len) {
                int state = -1;
                constexpr int STATE_CONFLICT = 0;
                constexpr int STATE_ALL_WILDCARD = 1;
                constexpr int STATE_ALL_CHAR = 2;

                // judge: all ?, all ? and single char, multiple char (conflict)
                do {
                    if (len >= min_len) {
                        state = STATE_CONFLICT;
                        break;
                    } else {
                        int wildcard_mask = get_mask('?', len);
                        if ((bs & wildcard_mask) == bs) {
                            state = STATE_ALL_WILDCARD;
                            break;
                        }
                        int rem_mask = bs ^ (bs & wildcard_mask);
                        int one_rem_idx = __builtin_ctz(rem_mask);
                        assert(one_rem_idx < n);
                        assert(len < v[one_rem_idx].size());
                        char one_c = v[one_rem_idx][len];
                        if ((rem_mask & get_mask(one_c, len)) == rem_mask) {
                            state = STATE_ALL_CHAR;
                            break;
                        } else {
                            state = STATE_CONFLICT;
                            break;
                        }
                    }
                } while (false);
                if (state == STATE_CONFLICT) {
                    break;
                }

                if (state == STATE_ALL_WILDCARD) {
                    (cur_prefix *= 26);
                }
                // cerr << "add " << cur_prefix << '\n';
                (cur_add += cur_prefix);
            }
            // cerr << "total " << cur_add << '\n';
            (ans += sgn * cur_add);
        }
        out << ans << '\n';
    }

public:
    ostringstream out;
};

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
    vector<test_instance> instances(t + 1);
    vector<thread> threads(t + 1);

    cerr << fixed << setprecision(3);

    for (int no = 1; no <= t; no++) {
        instances[no].input();
    }

    for (int no = 1; no <= t; no++) {
        threads[no] = thread(&test_instance::solve, &instances[no]);
    }

    for (int tc = 1; tc <= t; tc++) {
        threads[tc].join();
        string output = instances[tc].out.str();
        cout << "Case #" << tc << ": " << output;

#ifdef LOCAL
        cerr << "\e[0;32m"
             << "TIME ELAPSED: test " << tc << ' ' << double(clock() - start_time) / CLOCKS_PER_SEC
             << '\n';
#endif

        cout << flush;
        assert(!output.empty());
    }
}
