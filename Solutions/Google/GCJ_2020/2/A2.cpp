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

long long ss(long long st, long long ed, long long inc) {
    return (st+ed)*((ed-st)/inc+1)/2;
}

void solve() {
    long long l, r;
    cin >> l >> r;
    long long turns = 0;
    long long hi = 2e9, lo = -1;
    while (hi-lo > 1) {
        long long mi = (hi+lo)/2;
        long long sum = (1+mi)*mi/2;
        if (max(l, r)-sum <= min(l, r)) hi = mi;
        else lo = mi;
    }
    turns = hi;
//    cerr << "turns " << turns << '\n';
    long long sum = (1+hi)*hi/2;
    if (l>=r) l -= sum;
    else r -= sum;

    if (l < 0) l += turns, turns--;
    if (r < 0) r += turns, turns--;

//    cerr << l << ' ' << r << '\n';

    // now sign flip

    hi = 2e9, lo = turns;
    turns++;
    while (hi-lo>1) {
        long long mi = (hi+lo)/2;
        long long last_odd, last_even;
        if (mi%2) last_odd = mi, last_even = mi-1;
        else last_even = mi, last_odd = mi-1;

        long long s_even = ss(turns+turns%2, last_even, 2);
        long long s_odd = ss(turns+((turns%2)^1), last_odd, 2);

//        cerr << mi << ' ' << s_even << ' ' << s_odd << '\n';


        if (turns % 2) {
            if (max(l, r)-s_odd >= 0 && min(l, r)-s_even >= 0) lo = mi;
            else hi = mi;
        }
        else {
            if (max(l, r)-s_even >= 0 && min(l, r)-s_odd >= 0) lo = mi;
            else hi = mi;
        }
    }

//    cerr << "turns2 " << lo << '\n';

    long long mi = lo;
    long long last_odd, last_even;
    if (mi%2) last_odd = mi, last_even = mi-1;
    else last_even = mi, last_odd = mi-1;

    long long s_even = ss(turns+turns%2, last_even, 2);
    long long s_odd = ss(turns+((turns%2)^1), last_odd, 2);

    if (turns % 2) {
        if (l >= r) l -= s_odd, r -= s_even;
        else r -= s_odd, l -= s_even;
    }
    else {
        if (l >= r) l -= s_even, r -= s_odd;
        else r -= s_even, l -= s_odd;
    }

    cout << hi-1 << ' ' << l << ' ' << r << '\n';
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