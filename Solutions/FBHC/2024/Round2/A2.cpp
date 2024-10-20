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

vector<string> all_decs;

void dfs(int dig, string cur)
{
    for (int len = 1; len + cur.size() <= 9; ++len) {
        string t = string(len, '0' + dig);
        all_decs.push_back(cur + t);
        for (int nd = 1; nd < dig; ++nd) {
            dfs(nd, cur + t);
        }
    }
}

#ifndef KXSORT_H__
#define KXSORT_H__

#include <algorithm>
#include <iterator>

namespace kx {

static const int kRadixBits = 8;
static const size_t kInsertSortThreshold = 64;
static const int kRadixMask = (1 << kRadixBits) - 1;
static const int kRadixBin = 1 << kRadixBits;

//================= HELPING FUNCTIONS ====================

template<class T>
struct RadixTraitsUnsigned {
    static const int nBytes = sizeof(T);
    int kth_byte(const T& x, int k) { return (x >> (kRadixBits * k)) & kRadixMask; }
    bool compare(const T& x, const T& y) { return x < y; }
};

template<class T>
struct RadixTraitsSigned {
    static const int nBytes = sizeof(T);
    static const T kMSB = T(0x80) << ((sizeof(T) - 1) * 8);
    int kth_byte(const T& x, int k) { return ((x ^ kMSB) >> (kRadixBits * k)) & kRadixMask; }
    bool compare(const T& x, const T& y) { return x < y; }
};

template<class RandomIt, class ValueType, class RadixTraits>
inline void insert_sort_core_(RandomIt s, RandomIt e, RadixTraits radix_traits)
{
    for (RandomIt i = s + 1; i < e; ++i) {
        if (radix_traits.compare(*i, *(i - 1))) {
            RandomIt j;
            ValueType tmp = *i;
            *i = *(i - 1);
            for (j = i - 1; j > s && radix_traits.compare(tmp, *(j - 1)); --j) {
                *j = *(j - 1);
            }
            *j = tmp;
        }
    }
}

template<class RandomIt, class ValueType, class RadixTraits, int kWhichByte>
inline void radix_sort_core_(RandomIt s, RandomIt e, RadixTraits radix_traits)
{
    RandomIt last_[kRadixBin + 1];
    RandomIt* last = last_ + 1;
    size_t count[kRadixBin] = {0};

    for (RandomIt i = s; i < e; ++i) {
        ++count[radix_traits.kth_byte(*i, kWhichByte)];
    }

    last_[0] = last_[1] = s;

    for (int i = 1; i < kRadixBin; ++i) {
        last[i] = last[i - 1] + count[i - 1];
    }

    for (int i = 0; i < kRadixBin; ++i) {
        RandomIt end = last[i - 1] + count[i];
        if (end == e) {
            last[i] = e;
            break;
        }
        while (last[i] != end) {
            ValueType swapper = *last[i];
            int tag = radix_traits.kth_byte(swapper, kWhichByte);
            if (tag != i) {
                do {
                    std::swap(swapper, *last[tag]++);
                } while ((tag = radix_traits.kth_byte(swapper, kWhichByte)) != i);
                *last[i] = swapper;
            }
            ++last[i];
        }
    }

    if (kWhichByte > 0) {
        for (int i = 0; i < kRadixBin; ++i) {
            if (count[i] > kInsertSortThreshold) {
                radix_sort_core_<RandomIt, ValueType, RadixTraits,
                    (kWhichByte > 0 ? (kWhichByte - 1) : 0)>(last[i - 1], last[i], radix_traits);
            } else if (count[i] > 1) {
                insert_sort_core_<RandomIt, ValueType, RadixTraits>(
                    last[i - 1], last[i], radix_traits);
            }
        }
    }
}

template<class RandomIt, class ValueType, class RadixTraits>
inline void radix_sort_entry_(RandomIt s, RandomIt e, ValueType*, RadixTraits radix_traits)
{
    if (e - s <= (int)kInsertSortThreshold)
        insert_sort_core_<RandomIt, ValueType, RadixTraits>(s, e, radix_traits);
    else
        radix_sort_core_<RandomIt, ValueType, RadixTraits, RadixTraits::nBytes - 1>(
            s, e, radix_traits);
}

template<class RandomIt, class ValueType>
inline void radix_sort_entry_(RandomIt s, RandomIt e, ValueType*)
{
    if (ValueType(-1) > ValueType(0)) {
        radix_sort_entry_(s, e, (ValueType*)(0), RadixTraitsUnsigned<ValueType>());
    } else {
        radix_sort_entry_(s, e, (ValueType*)(0), RadixTraitsSigned<ValueType>());
    }
}

//================= INTERFACES ====================

template<class RandomIt, class RadixTraits>
inline void radix_sort(RandomIt s, RandomIt e, RadixTraits radix_traits)
{
    typename std::iterator_traits<RandomIt>::value_type* dummy(0);
    radix_sort_entry_(s, e, dummy, radix_traits);
}

template<class RandomIt>
inline void radix_sort(RandomIt s, RandomIt e)
{
    typename std::iterator_traits<RandomIt>::value_type* dummy(0);
    radix_sort_entry_(s, e, dummy);
}

}  // namespace kx

#endif

vector<ll> all_mountains;
auto precom = []() {
    cerr << "begin\n";
    for (int dig = 1; dig <= 9; ++dig) {
        dfs(dig, "");
    }

    vector<ll> safe_10pow;
    safe_10pow.push_back(1);
    for (int i = 0; i < 18; i++) {
        safe_10pow.push_back(safe_10pow.back() * 10);
    }

    for (int dig = 1; dig <= 9; ++dig) {
        ll x = dig;
        all_mountains.push_back(x);
    }

    for (int dig = 1; dig <= 9; ++dig) {
        for (int len = 1; len <= 8; ++len) {
            vector<ll> inc_ints;
            vector<ll> dec_ints;
            for (string s : all_decs) {
                if (s.size() != len) {
                    continue;
                }
                if (s[0] < '0' + dig) {
                    dec_ints.push_back(stoll(s));
                    string rev_s = s;
                    reverse(rev_s.begin(), rev_s.end());
                    inc_ints.push_back(stoll(rev_s));
                }
            }
            for (auto inci : inc_ints) {
                for (auto deci : dec_ints) {
                    ll x = (inci * 10 + dig) * safe_10pow[len] + deci;
                    all_mountains.push_back(x);
                }
            }
        }
    }
    kx::radix_sort(all_mountains.begin(), all_mountains.end());
    cerr << "done " << all_mountains.size() << '\n';
    return 0;
};

void solve()
{
    long long a, b, m;
    cin >> a >> b >> m;
    int ans = 0;

    auto start_it = lower_bound(all_mountains.begin(), all_mountains.end(), a);
    for (auto it = start_it; it != all_mountains.end(); ++it) {
        ll x = *it;
        if (x > b) {
            break;
        }
        if (x % m == 0) {
            ++ans;
        }
    }

    cout << ans << '\n';
}

int main()
{
    precom();
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
    for (int no = 1; no <= t; no++) {
        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "\e[0;32m"
         << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}
