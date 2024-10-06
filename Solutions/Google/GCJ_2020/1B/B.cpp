#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

#define DEBUG 0
#define cerr if (DEBUG) cerr
#define test cerr << "hi\n";

#define INF 0x3f3f3f3f3f3f3f3f
#define MAXN 500005
#define MOD 998244353LL

long long a, b;
long long R = 1000000000-50;

long long ccx = 42, ccy = -13;

bool ask(long long x, long long y) {
//    return (ccx-x)*(ccx-x) + (ccy-y)*(ccy-y) <= R*R;
    cout << x << ' ' << y << endl;
    fflush(stdout);
    string s; cin >> s;
    return s == "HIT";
}

bool work(long long x, long long y, long long ccx, long long ccy) {
    return (ccx-x)*(ccx-x) + (ccy-y)*(ccy-y) <= R*R;
}

long long ss(long long x) {
    long long hi = 1e9, lo = 0;
    while (hi - lo > 1) { //
        long long mi = (hi + lo)/2;
        if (mi*mi <= x) lo = mi;
        else hi = mi;
    }
    return lo;
}

void solve() {
    R = a;
    long long hi, lo, uy, dy, ux, dx;

    hi = 1e9, lo = 0;
    while (hi - lo > 1) { //
        long long mi = (hi + lo)/2;
        if (ask(9e8, mi)) lo = mi;
        else hi = mi;
    }
    uy = hi;

    hi = 1e9, lo = 0;
    while (hi - lo > 1) { //
        long long mi = (hi + lo)/2;
        if (ask(mi, 9e8)) lo = mi;
        else hi = mi;
    }
    ux = hi;

    for (int cx = -50; cx <= 50; cx++) {
        for (int cy = -50; cy <= 50; cy++) {
            long long uuy, uux;

            hi = 1e9, lo = 0;
            while (hi - lo > 1) { //
                long long mi = (hi + lo)/2;
                if (work(9e8, mi, cx, cy)) lo = mi;
                else hi = mi;
            }
            uuy = hi;

            hi = 1e9, lo = 0;
            while (hi - lo > 1) { //
                long long mi = (hi + lo)/2;
                if (work(mi, 9e8, cx, cy)) lo = mi;
                else hi = mi;
            }
            uux = hi;


            if (uuy == uy && uux == ux) {
                cout << cx << ' ' << cy << endl;
                fflush(stdout);
                string s;
                cin >> s;
                return;
            }
        }
    }
}

int main() {
//#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//#endif
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t >> a >> b;
    for (int no = 1; no <= t; no++) {
//        cout << "Case #" << no << ": ";
        solve();
    }
}