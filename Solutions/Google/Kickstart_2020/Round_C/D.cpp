#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 200005
#define MOD 998244353LL

#define SHIFT 20000020

int n, q;
long long a[MAXN];

template <class Type>
struct BIT {
    vector<Type> T;
    int n;
    BIT(int _n) {
        n = _n;
        T.resize(n+5, 0);
    }

    void add(int pos, Type x) {
        for (pos++; pos < n+5; pos += pos&-pos)
            T[pos] += x;
    }

    Type sum(int pos) {
        Type ret = 0;
        for (pos++; pos; pos -= pos&-pos)
            ret += T[pos];
        return ret;
    }

    Type sum(int l, int r) { // closed interval [l, r]
        return sum(r)-sum(l-1);
    }

};

void solve() {
    cin >> n >> q;
    BIT <long long> b1(n), b2(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b1.add(i, 1LL * (i%2 ? 1: -1) * a[i]);
        b2.add(i, 1LL * (i%2 ? 1: -1) * i * a[i]);
    }

    long long ans = 0;

    while (q--) {
        char t; cin >> t;
        if (t == 'Q') {
            long long l, r;
            cin >> l >> r;
            long long cur = b2.sum(l, r) - b1.sum(l, r) * (l-1);
            if (l % 2 == 0) cur *= -1;
            ans += cur;
        }
        else {
            long long pos, x;
            cin >> pos >> x;
            b1.add(pos, 1LL * (pos%2 ? 1: -1) * (-a[pos] + x));
            b2.add(pos, 1LL * (pos%2 ? 1: -1) * pos * (-a[pos] + x));
            a[pos] = x;
        }
    }

    cout << ans << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    auto start_time = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for (int no = 1; no <= t; no++) {
        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}