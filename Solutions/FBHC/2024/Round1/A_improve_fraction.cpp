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

struct fraction {
    // TODO: set this to false if it's unnecessary and the time limit might be tight.
    // CHECK_OVERFLOW64 = true can run up to 2 times slower (particularly on CF).
    static const bool CHECK_OVERFLOW64 = true;

    // TODO: consider setting AUTO_REDUCE = false for faster code. In this case, remember to call reduce() at the end.
    static const bool AUTO_REDUCE = true;

    static int cross_sign(const fraction& a, const fraction& b)
    {
        if (CHECK_OVERFLOW64) {
            long double double_value =
                (long double)a.numer * b.denom - (long double)b.numer * a.denom;

            if (abs(double_value) > 1e18)
                return (double_value > 0) - (double_value < 0);
        }

        uint64_t uint64_value = (uint64_t)a.numer * b.denom - (uint64_t)b.numer * a.denom;
        int64_t actual = int64_t(uint64_value);
        return (actual > 0) - (actual < 0);
    }

    int64_t numer, denom;

    fraction(int64_t n = 0, int64_t d = 1)
        : numer(n)
        , denom(d)
    {
        check_denom();

        if (AUTO_REDUCE)
            reduce();
    }

    void check_denom()
    {
        if (denom < 0) {
            numer = -numer;
            denom = -denom;
        }
    }

    void reduce()
    {
        int64_t g = __gcd(abs(numer), denom);
        numer /= g;
        denom /= g;
    }

    bool is_integer() const
    {
        return denom == 1 || (!AUTO_REDUCE && denom != 0 && numer % denom == 0);
    }

    friend fraction operator+(const fraction& a, const fraction& b)
    {
        return fraction(a.numer * b.denom + b.numer * a.denom, a.denom * b.denom);
    }

    friend fraction operator-(const fraction& a, const fraction& b)
    {
        return fraction(a.numer * b.denom - b.numer * a.denom, a.denom * b.denom);
    }

    friend fraction operator*(const fraction& a, const fraction& b)
    {
        return fraction(a.numer * b.numer, a.denom * b.denom);
    }

    friend fraction operator/(const fraction& a, const fraction& b)
    {
        return fraction(a.numer * b.denom, a.denom * b.numer);
    }

    fraction& operator+=(const fraction& other) { return *this = *this + other; }
    fraction& operator-=(const fraction& other) { return *this = *this - other; }
    fraction& operator*=(const fraction& other) { return *this = *this * other; }
    fraction& operator/=(const fraction& other) { return *this = *this / other; }

    fraction& operator++()
    {
        numer += denom;
        return *this;
    }
    fraction& operator--()
    {
        numer -= denom;
        return *this;
    }

    fraction operator++(int)
    {
        fraction before = *this;
        ++*this;
        return before;
    }
    fraction operator--(int)
    {
        fraction before = *this;
        --*this;
        return before;
    }

    fraction operator-() const { return fraction(-numer, denom); }

    fraction inv() const { return fraction(denom, numer); }

    bool operator==(const fraction& other) const { return cross_sign(*this, other) == 0; }
    bool operator!=(const fraction& other) const { return cross_sign(*this, other) != 0; }
    bool operator<(const fraction& other) const { return cross_sign(*this, other) < 0; }
    bool operator>(const fraction& other) const { return cross_sign(*this, other) > 0; }
    bool operator<=(const fraction& other) const { return cross_sign(*this, other) <= 0; }
    bool operator>=(const fraction& other) const { return cross_sign(*this, other) >= 0; }

    explicit operator double() const { return double(numer) / double(denom); }

    explicit operator long double() const { return (long double)numer / (long double)denom; }

    friend fraction abs(const fraction& f) { return fraction(abs(f.numer), f.denom); }

    friend ostream& operator<<(ostream& out, const fraction& frac)
    {
        return out << frac.numer << '/' << frac.denom;
    }
};

void solve()
{
    pair<fraction, fraction> ans;
    ans.first = 0;
    ans.second = 10000007;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long double a, b;
        cin >> a >> b;

        if (a > 0) {
            ans.second = min(ans.second, fraction(i + 1, a));
        }
        ans.first = max(ans.first, fraction(i + 1, b));
    }
    if (ans.first > ans.second) {
        cout << -1 << '\n';
        return;
    }
    cout << static_cast<double>(ans.first) << '\n';
}

int main()
{
#ifdef LOCAL
    auto start_time = clock();
    freopen("full_in.txt", "r", stdin);
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
