#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize ("trapv")
using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define DEBUG 1
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<long long>(l, r)(rng)
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 300005
//#define MOD 998244353LL
#define MOD 1000000007LL

long long T1[MAXN], T2[MAXN], T3[MAXN], a[MAXN], b[MAXN], c[MAXN];
int n, q;

void add(long long T[], int x, long long v) {
    for (; x < MAXN; x += x&-x)
        T[x] += v;
}

long long sum(long long T[], int x) {
    long long ans = 0;
    for (; x; x -= x&-x)
        ans += T[x];
    return ans;
}

void fix() {
    long long original = sum(T1, 1)+sum(T2, 1);
    long long m1 = sum(T1, 1);
    long long m2 = sum(T2, n);

    long long target = (m1+m2)/2;
    add(T1, 1, target-m1);
    add(T1, n+1, -(target-m1));
    add(T2, 1, target-m2);
    add(T2, n+1, -(target-m2));

    long long d = original-(sum(T1, 1)+sum(T2, 1));

    if (sum(T1, 1) < sum(T2, n)) {
        add(T1, 1, d);
        add(T1, n+1, -d);
    }
    else {
        add(T2, 1, d);
        add(T2, n+1, -d);
    }
}

void print() {
    cerr << "B: ";
    for (int i = 1; i <= n; i++)
        cerr << sum(T1, i) << " \n"[i==n];
    cerr << "C: ";
    for (int i = 1; i <= n; i++)
        cerr << sum(T2, i) << " \n"[i==n];
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    b[1] = 1e9;
    c[1] = a[1]-b[1];

    for (int i = 2; i <= n; i++) {
        if (a[i] <= a[i-1]) {
            b[i] = b[i-1] - (a[i-1]-a[i]);
            c[i] = c[i-1];
        }
        else {
            b[i] = b[i-1];
            c[i] = c[i-1] + (a[i]-a[i-1]);
        }
    }

    for (int i = 1; i <= n; i++) {
//        cout << b[i] << " \n"[i==n];
        add(T1, i, b[i]);
        add(T1, i+1, -b[i]);
    }
    for (int i = 1; i <= n; i++) {
//        cout << c[i] << " \n"[i==n];
        add(T2, i, c[i]);
        add(T2, i+1, -c[i]);
    }
    for (int i = 1; i <= n; i++) {
//        cout << c[i] << " \n"[i==n];
        add(T3, i, a[i]);
        add(T3, i+1, -a[i]);
    }

    fix();
//    print();
    cout << max(sum(T1, 1), sum(T2, n)) << '\n';
    cin >> q;
    while (q--) {
        int l, r;
        long long v;
        cin >> l >> r >> v;

        add(T3, l, v);
        add(T3, r+1, -v);

        if (v > 0) {
            add(T1, 1, v);
            add(T1, r+1, -v);
            add(T2, 1, -v);
            add(T2, l, v);
        }
        else {
            add(T2, 1, v);
            add(T2, r+1, -v);
            add(T1, 1, -v);
            add(T1, l, v);
        }

        if (sum(T3, l) <= sum(T3, l-1)) {
            // make c[i] = c[i-1];
            long long d = (sum(T2, l)-sum(T2, l-1));

            add(T2, 1, d);
            add(T2, l, -d);
            add(T1, 1, -d);
            add(T1, l, d);
        }
        else {
            // make b[i] = b[i-1];
            long long d = (sum(T1, l)-sum(T1, l-1));

            add(T1, 1, d);
            add(T1, l, -d);
            add(T2, 1, -d);
            add(T2, l, d);
        }
        /////////////////////
        if (sum(T3, r+1) <= sum(T3, r)) {
            // make c[i] = c[i-1];
            long long d = -(sum(T2, r+1)-sum(T2, r));

            add(T2, r+1, d);
//            add(T2, n, -d);
            add(T1, r+1, -d);
//            add(T1, n, d);
        }
        else {
            // make b[i] = b[i-1];
            long long d = -(sum(T1, r+1)-sum(T1, r));

            add(T1, r+1, d);
//            add(T1, n, -d);
            add(T2, r+1, -d);
//            add(T2, n, d);
        }

        fix();
//        print();

        cout << max(sum(T1, 1), sum(T2, n)) << '\n';
    }


}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    auto start_time = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "TIME ELAPSED: " << double(clock() - start_time) / CLOCKS_PER_SEC << '\n';
#endif
}